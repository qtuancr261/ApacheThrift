#ifndef MYSERVICEHANDLER_H
#define MYSERVICEHANDLER_H


#include "MyService.h"
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TNonblockingServer.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TServerSocket.h>
#include <Poco/Util/ServerApplication.h>
#include <thrift/server/TThreadedServer.h>
#include <iostream>
#include <exception>
#include <map>
#include <string>
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;
using boost::shared_ptr;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::pair;
using std::make_pair;
using std::exception;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using namespace ::ZTE;

class MyServiceHandler : virtual public MyServiceIf
{
private:
    map<string, MyData> receivedDataFromClients;
public:
    MyServiceHandler();

    int64_t send(const std::string& p1, const int32_t p2, const int64_t p3, const std::vector<int32_t>& p4, const std::vector<std::string>& p5, const std::map<std::string, int32_t>& p6);

    void receive(MyData& _return, const std::string& p1);

    void getData(const std::string& p3);
};
#endif // MYSERVICEHANDLER_H
