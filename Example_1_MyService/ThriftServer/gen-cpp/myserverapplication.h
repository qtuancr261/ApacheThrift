#ifndef MYSERVERAPPLICATION_H
#define MYSERVERAPPLICATION_H

#include <Poco/Util/Application.h>
#include <Poco/Util/ServerApplication.h>
#include <Poco/Util/Subsystem.h>
#include <Poco/Util/HelpFormatter.h>
#include <Poco/Util/IniFileConfiguration.h>
#include <Poco/Logger.h>
#include <Poco/SimpleFileChannel.h>
#include <Poco/FileChannel.h>
#include <Poco/AutoPtr.h>
#include <Poco/PatternFormatter.h>
#include <Poco/FormattingChannel.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <boost/make_shared.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "myservicehandler.h"
#include "myserviceclonefactory.h"

using Poco::Util::Application;
using Poco::Util::ServerApplication;
using Poco::Util::OptionSet;
using Poco::Util::Option;
using Poco::Util::OptionCallback;
using Poco::Util::HelpFormatter;
using Poco::AutoPtr;
using Poco::Util::IniFileConfiguration;
using Poco::Logger;
using Poco::FileChannel;
using Poco::PatternFormatter;
using Poco::FormattingChannel;
using ::apache::thrift::server::TThreadedServer;
using boost::make_shared;
using std::cout;
using std::string;
using std::vector;
using std::endl;
class MyServerApplication : public ServerApplication
{
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
    void initialize(Application& self) override;
    void uninitialize() override;
    void defineOptions(OptionSet& optionSet) override;
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
    void handeRunServerService(const string&name , const string& value);

    bool readConfigurationForServer();

    // the main function
    int main(const vector<string>& args) override;


};

#endif // MYSERVERAPPLICATION_H
