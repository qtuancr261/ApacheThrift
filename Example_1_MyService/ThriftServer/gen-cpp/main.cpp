#include "Poco/Logger.h"
#include "Poco/SimpleFileChannel.h"
#include "Poco/AutoPtr.h"
#include "myserverapplication.h"
#include "myservicehandler.h"
using Poco::Logger;
using Poco::SimpleFileChannel;
using Poco::AutoPtr;
int main(int argc, char** argv)
{
    MyServerApplication myApp;
    return myApp.run(argc, argv);
}
