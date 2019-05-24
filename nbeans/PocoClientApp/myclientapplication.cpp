#include "myclientapplication.h"

MyClientApplication::MyClientApplication()
    : ServerApplication()
    , helpRequested{ false }
    , startServerRequested{ false }
    , versionRequested{ false }
    , isServerHasBeenConfigured{ false }
    , serverPort{ 8888 }
    , ptrFileChannel{ new FileChannel() }
    , ptrPatternFormatter{ new PatternFormatter() }
    , ptrFormattingChannel{ new FormattingChannel(ptrPatternFormatter, ptrFileChannel) }
    , logger{ [this]() -> Logger& { Logger::root().setChannel(ptrFormattingChannel);return Logger::get("TestLogger"); }() }
{
    ptrFileChannel->setProperty("path", "client.log");
    ptrFileChannel->setProperty("rotation", "10240 M");
    ptrFileChannel->setProperty("archive", "number");
    ptrFileChannel->setProperty("purgeCount", "9");
    ptrFileChannel->setProperty("times", "local");

    ptrPatternFormatter->setProperty("pattern", "%Y-%m-%d %H:%M:%S %s: %t");
    ptrPatternFormatter->setProperty("times", "local");
    //for (int timeT{}; timeT < 100000; timeT++)

    readConfigurationForServer();
    logger.information("Finished Configuring Client Application");
}

void MyClientApplication::initialize(Poco::Util::Application& self)
{
    logger.information("Initializing Client Application");
    config().setString("optionval", "defaultoption");
    // loaf the default configuration files
    loadConfiguration();
    Application::initialize(self);
}

void MyClientApplication::uninitialize()
{
    logger.information("Uninitializing Server Application");
    Application::uninitialize();
}

void MyClientApplication::defineOptions(Poco::Util::OptionSet& optionSet)
{
    ServerApplication::defineOptions(optionSet);
    optionSet.addOption(Option("help", "h", "Help Information")
                            .required(false)
                            .repeatable(false)
                            .callback(OptionCallback<MyClientApplication>(this, &MyClientApplication::handleHelp)));

    optionSet.addOption(Option("version", "v", "Showing application's version")
                            .required(false)
                            .repeatable(false)
                            .callback(OptionCallback<MyClientApplication>(this, &MyClientApplication::handleDisplayVersion)));
    optionSet.addOption(Option("type", "t", "Choose Thrift Server type")
                            .required(true)
                            .repeatable(false)
                            .argument("type")
                            .callback(OptionCallback<MyClientApplication>(this, &MyClientApplication::handeRunClientService)));
}

void MyClientApplication::displayHelpInformation()
{
    HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("OPTIONS");
    helpFormatter.setHeader(
        "A Client application that use Apache Thrift and POCO ");
    helpFormatter.format(std::cout);
}

void MyClientApplication::handleHelp(const std::string& name, const std::string& value)
{
    helpRequested = true;
    displayHelpInformation();
    stopOptionsProcessing();
}

void MyClientApplication::displayVersionInformation()
{
    cout << "My ClientApplication 1.0 (07/2018)" << endl;
}

void MyClientApplication::handleDisplayVersion(const std::string& name, const std::string& value)
{
    versionRequested = true;
    displayVersionInformation();
    stopOptionsProcessing();
}

void MyClientApplication::runSingleThreadClient()
{
    shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
    // Others transports are often wrapped around in this one, it provides buffering of input and output data
    shared_ptr<TTransport> transport(new TBufferedTransport(socket));

    shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

    MyServiceClient client(protocol);
    transport->open();
    // Let's do it
    MyData data_1{};
    MyServiceClientFunction::generateMyData(data_1, 5);
    string key{ data_1.p1 };
    client.send(data_1.p1, data_1.p2, data_1.p3, data_1.p4, data_1.p5, data_1.p6);
    cout << "Client has sent data with p1: " << data_1.p1 << " p2: " << data_1.p2 << " p3: " << data_1.p3 << endl;
    // Generate data again and resend
    MyServiceClientFunction::generateMyData(data_1, 2);
    client.send(data_1.p1, data_1.p2, data_1.p3, data_1.p4, data_1.p5, data_1.p6);
    cout << "Client has sent data with p1: " << data_1.p1 << " p2: " << data_1.p2 << " p3: " << data_1.p3 << endl;
    // Receive data from p1
    client.receive(data_1, key);
    cout << "Client received data with p1: " << data_1.p1 << " p2: " << data_1.p2 << " p3: " << data_1.p3 << endl;
    cout << "Stop" << endl;
    transport->close();
}

void MyClientApplication::runMultiThreadClient()
{
    MyServiceClientRunnable run12;
    MyServiceClientRunnable run13;
    MyServiceClientRunnable run14;
    Poco::ThreadPool::defaultPool().start(run12);
    Poco::ThreadPool::defaultPool().start(run13);
    Poco::ThreadPool::defaultPool().start(run14);
    Poco::ThreadPool::defaultPool().joinAll();
}

void MyClientApplication::handeRunClientService(const std::string& name, const std::string& value)
{
    if (value == "1") {
        cout << "Single Thread" << endl;
        logger.information("Start running single thread client");
        runSingleThreadClient();
    } else if (value == "2") {
        cout << "Multi Thread" << endl;
        logger.information("Start running multi thread client");
        runMultiThreadClient();
    }
}

bool MyClientApplication::readConfigurationForServer()
{
    cout << "Reading configuration from file ThriftClient.ini" << endl;
    AutoPtr<IniFileConfiguration> ptrConfiFile{ new IniFileConfiguration("ThriftClient.ini") };
    string serverPortStr{ ptrConfiFile->getString("port") };
    serverPort = std::atoi(serverPortStr.c_str());
    logger.information("Reading configuration and set port for client to connect to: " + serverPortStr);
    return true;
}

int MyClientApplication::main(const vector<std::string>& args)
{
    if (Application::argv().size() == 1)
        cout << "Missing arguments.\nPlease use -h or --help for more information\n";
    waitForTerminationRequest();
    return 0;
}
