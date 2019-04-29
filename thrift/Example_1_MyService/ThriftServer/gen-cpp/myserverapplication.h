#ifndef MYSERVERAPPLICATION_H
#define MYSERVERAPPLICATION_H

#include "myserviceclonefactory.h"
#include "myservicehandler.h"
#include <Poco/AutoPtr.h>
#include <Poco/Environment.h>
#include <Poco/FileChannel.h>
#include <Poco/FormattingChannel.h>
#include <Poco/Logger.h>
#include <Poco/PatternFormatter.h>
#include <Poco/SimpleFileChannel.h>
#include <Poco/Util/Application.h>
#include <Poco/Util/HelpFormatter.h>
#include <Poco/Util/IniFileConfiguration.h>
#include <Poco/Util/ServerApplication.h>
#include <Poco/Util/Subsystem.h>
#include <boost/make_shared.hpp>
#include <iostream>
#include <string>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/server/TThreadedServer.h>
#include <vector>

using ::apache::thrift::server::TThreadedServer;
using boost::make_shared;
using Poco::AutoPtr;
using Poco::Environment;
using Poco::FileChannel;
using Poco::FormattingChannel;
using Poco::Logger;
using Poco::PatternFormatter;
using Poco::Util::Application;
using Poco::Util::HelpFormatter;
using Poco::Util::IniFileConfiguration;
using Poco::Util::Option;
using Poco::Util::OptionCallback;
using Poco::Util::OptionSet;
using Poco::Util::ServerApplication;
using std::cout;
using std::endl;
using std::string;
using std::vector;
class MyServerApplication : public ServerApplication {
private:
    bool helpRequested;
    bool startServerRequested;
    bool versionRequested;
    bool isServerHasBeenConfigured;
    int serverPort;
    AutoPtr<FileChannel> ptrFileChannel;
    AutoPtr<PatternFormatter> ptrPatternFormatter;
    AutoPtr<FormattingChannel> ptrFormattingChannel;
    Logger& logger;

public:
    MyServerApplication();
    virtual void initialize(Application& self) override;
    virtual void uninitialize() override;
    virtual void defineOptions(OptionSet& optionSet) override;
    // handler option functions
    void displayHelpInformation();
    void handleHelp(const string& name, const string& value);

    void displayVersionInformation();
    void handleDisplayVersion(const string& name, const string& value);

    void runTSimpleServerService();
    void runTNonblockingServerService();
    void runTThreadedServerService();
    void runTThreadedServerService_noNeedPerConnectionState();
    void runTThreadedPoolServer();
    void handeRunServerService(const string& name, const string& value);

    bool readConfigurationForServer();

    // the main function
    int main(const vector<string>& args) override;
};

#endif // MYSERVERAPPLICATION_H
