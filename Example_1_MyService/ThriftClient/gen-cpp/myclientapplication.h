#ifndef MYCLIENTAPPLICATION_H
#define MYCLIENTAPPLICATION_H
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
#include <iostream>
#include <string>
#include <vector>
#include "myserviceclientrunnable.h"

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
using std::cout;
using std::string;
using std::vector;
using std::endl;
class MyClientApplication : public ServerApplication
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
    MyClientApplication();
    void initialize(Application& self) override;
    void uninitialize() override;
    void defineOptions(OptionSet& optionSet) override;
    // handler option functions
    void displayHelpInformation();
    void handleHelp(const string& name, const string& value);

    void displayVersionInformation();
    void handleDisplayVersion(const string& name, const string& value);

    void runSingleThreadClient();
    void runMultiThreadClient();
    void handeRunClientService(const string&name , const string& value);

    bool readConfigurationForServer();

    // the main function
    int main(const vector<string>& args) override;

};

#endif // MYCLIENTAPPLICATION_H
