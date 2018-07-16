#ifndef MYSERVERAPPLICATION_H
#define MYSERVERAPPLICATION_H
#include <Poco/Util/Application.h>
#include <Poco/Util/ServerApplication.h>
#include <Poco/Util/Subsystem.h>
#include <Poco/Util/HelpFormatter.h>
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

    // the main function
    int main(const vector<string>& args) override;


};

#endif // MYSERVERAPPLICATION_H
