#include "myserverapplication.h"

MyServerApplication::MyServerApplication()
    : ServerApplication(), helpRequested{false}, startServerRequested{false}, versionRequested{false}
{

}

void MyServerApplication::initialize(Poco::Util::Application &self)
{
    config().setString("optionval", "defaultoption");
    // loaf the default configuration files
    loadConfiguration();
    Application::initialize(self);
}

void MyServerApplication::uninitialize()
{
    // Call the base class method :3
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
                        .required(false)
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
}

void MyServerApplication::runTSimpleServerService()
{
    //cout << "Running" << endl;
    int port = 8888;
    shared_ptr<MyServiceHandler> handler(new MyServiceHandler());
    shared_ptr<TProcessor> processor(new MyServiceProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
    printf("Running TSimpleServer on port %d", port);
    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);

    server.serve();
}

void MyServerApplication::runTNonblockingServerService()
{
    int port = 8888;
    shared_ptr<MyServiceHandler> handler(new MyServiceHandler());
    shared_ptr<TProcessor> processor(new MyServiceProcessor(handler));
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    // using thread pool with maximum 15 threads to handle incoming requests
    shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(15);
    shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
    threadManager->threadFactory(threadFactory);
    threadManager->start();
    TNonblockingServer server(processor, protocolFactory, port, threadManager);
    server.serve();
}

void MyServerApplication::handeRunServerService(const std::string &name, const std::string &value)
{
    if (value == "1")
    {
        cout << "TSimpleServer" << endl;
        runTSimpleServerService();
    }
    else if (value =="2")
    {
        cout << "TNonblockingServer" << endl;
        runTNonblockingServerService();
    }
}

int MyServerApplication::main(const vector<std::string> &args)
{
    if (Application::argv().size() == 1)
        cout << "Missing arguments.\nPlease use -h or --help for more information\n";
    waitForTerminationRequest();
    return 0;
}
