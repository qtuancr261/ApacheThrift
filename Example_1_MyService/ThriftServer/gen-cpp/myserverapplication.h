#ifndef MYSERVERAPPLICATION_H
#define MYSERVERAPPLICATION_H

#include <Poco/Util/Application.h>
#include <Poco/Util/ServerApplication.h>
#include <Poco/Util/Subsystem.h>
#include <Poco/Util/HelpFormatter.h>
#include <Poco/Util/IniFileConfiguration.h>
#include <Poco/Logger.h>
#include <Poco/SimpleFileChannel.h>
#include <Poco/AutoPtr.h>
#include <iostream>
#include <string>
#include <vector>
#include "myservicehandler.h"

using Poco::Util::Application;
using Poco::Util::ServerApplication;
using Poco::Util::OptionSet;
using Poco::Util::Option;
using Poco::Util::OptionCallback;
using Poco::Util::HelpFormatter;
using Poco::AutoPtr;
using Poco::Util::IniFileConfiguration;
using Poco::Logger;
using Poco::SimpleFileChannel;
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
    AutoPtr<SimpleFileChannel> ptrFileChannel;
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
    void handeRunServerService(const string&name , const string& value);

    bool readConfigurationForServer();

    // the main function
    int main(const vector<string>& args) override;


};

#endif // MYSERVERAPPLICATION_H
