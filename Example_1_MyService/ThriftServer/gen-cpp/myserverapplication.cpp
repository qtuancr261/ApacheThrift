#include "myserverapplication.h"

MyServerApplication::MyServerApplication()
    : ServerApplication(),
      helpRequested{false},
      startServerRequested{false},
      versionRequested{false},
      isServerHasBeenConfigured{false},
      serverPort{8888},
      ptrFileChannel{new FileChannel()},
      ptrPatternFormatter{new PatternFormatter()},
      ptrFormattingChannel{new FormattingChannel(ptrPatternFormatter, ptrFileChannel)},
      logger{[this]() -> Logger& { Logger::root().setChannel(ptrFormattingChannel);return Logger::get("TestLogger");}()}
{

    ptrFileChannel->setProperty("path", "server.log");
    ptrFileChannel->setProperty("rotation", "10240 M");
    ptrFileChannel->setProperty("archive", "number");
    ptrFileChannel->setProperty("purgeCount", "9");
    ptrFileChannel->setProperty("times", "local");

    ptrPatternFormatter->setProperty("pattern", "%Y-%m-%d %H:%M:%S %s: %t");
    ptrPatternFormatter->setProperty("times", "local");
    //for (int timeT{}; timeT < 100000; timeT++)

    readConfigurationForServer();
    logger.information("Finished Configuring Server Application");
}

void MyServerApplication::initialize(Poco::Util::Application &self)
{
    logger.information("Initializing Server Application");
    config().setString("optionval", "defaultoption");
    // loaf the default configuration files
    loadConfiguration();
    Application::initialize(self);
}

void MyServerApplication::uninitialize()
{
    // Call the base class method :3
    logger.information("Uninitializing Server Application");
    Application::uninitialize();
}

void MyServerApplication::defineOptions(Poco::Util::OptionSet &optionSet)
{

    ServerApplication::defineOptions(optionSet);
    optionSet.addOption(Option("help", "h", "Help Information")
                        .required(false)
                        .repeatable(false)
                        .callback(OptionCallback<MyServerApplication>(this, &MyServerApplication::handleHelp)));

    optionSet.addOption(Option("version", "v", "Showing application's version")
                        .required(false)
                        .repeatable(false)
                        .callback(OptionCallback<MyServerApplication>(this, &MyServerApplication::handleDisplayVersion)));
    optionSet.addOption(Option("type", "t", "Choose Thrift Server type")
                        .required(true)
                        .repeatable(false)
                        .argument("type")
                        .callback(OptionCallback<MyServerApplication>(this, &MyServerApplication::handeRunServerService)));
}

void MyServerApplication::displayHelpInformation()
{
    HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("OPTIONS");
    helpFormatter.setHeader(
        "A Server application that use Apache Thrift and POCO ");
    helpFormatter.format(std::cout);
}

void MyServerApplication::handleHelp(const std::string &name, const std::string &value)
{
    helpRequested = true;
    displayHelpInformation();
    stopOptionsProcessing();
    terminate();
}

void MyServerApplication::displayVersionInformation()
{
    cout << "My ServerApplication 1.0 (07/2018)" << endl;
}

void MyServerApplication::handleDisplayVersion(const std::string &name, const std::string &value)
{
    versionRequested = true;
    displayVersionInformation();
    stopOptionsProcessing();
    terminate();
}

void MyServerApplication::runTSimpleServerService()
{
    //cout << "Running" << endl;
    shared_ptr<MyServiceHandler> handler(new MyServiceHandler());
    shared_ptr<TProcessor> processor(new MyServiceProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(serverPort));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);

    server.serve();
}

void MyServerApplication::runTNonblockingServerService()
{
    shared_ptr<MyServiceHandler> handler(new MyServiceHandler());
    shared_ptr<TProcessor> processor(new MyServiceProcessor(handler));
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    // using thread pool with maximum 15 threads to handle incoming requests
    shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(15);
    shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
    threadManager->threadFactory(threadFactory);
    threadManager->start();
    TNonblockingServer server(processor, protocolFactory, serverPort, threadManager);
    server.serve();
}

void MyServerApplication::handeRunServerService(const std::string &name, const std::string &value)
{
    if (value == "1")
    {
        cout << "TSimpleServer" << endl;
        logger.information("Start running TSimpleServer");
        runTSimpleServerService();
    }
    else if (value =="2")
    {
        cout << "TNonblockingServer" << endl;
        logger.information("Start running TNonblockingServer");
        runTNonblockingServerService();
    }
}

bool MyServerApplication::readConfigurationForServer()
{
    cout << "Reading configuration from file ThriftServer.ini" << endl;
    AutoPtr<IniFileConfiguration> ptrConfiFile{new IniFileConfiguration("ThriftServer.ini")};
    string serverPortStr{ptrConfiFile->getString("port")};
    serverPort = std::atoi(serverPortStr.c_str());
    logger.information("Reading configuration and set port to: " + serverPortStr);
    return true;
}

int MyServerApplication::main(const vector<std::string> &args)
{
    if (Application::argv().size() == 1)
        cout << "Missing arguments.\nPlease use -h or --help for more information\n";
    waitForTerminationRequest();
    return 0;
}
