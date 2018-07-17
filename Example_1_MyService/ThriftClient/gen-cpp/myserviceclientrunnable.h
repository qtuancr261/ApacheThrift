#ifndef MYSERVICECLIENTRUNNABLE_H
#define MYSERVICECLIENTRUNNABLE_H
#include "MyService.h"
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/transport/TSocket.h>
#include <Poco/ThreadPool.h>
#include <Poco/Runnable.h>
using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::ZTE;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;
using boost::shared_ptr;

namespace MyServiceClientFunction
{
    string random_string(size_t length);
    //Template for randoming int
    template <typename T>
    T random_int(T range)
    {
        return rand() % range;
    }

    void generateMyData(MyData& preparedData, size_t p1Size);
}
class MyServiceClientRunnable : public Poco::Runnable
{
public:
    MyServiceClientRunnable() = default;
    virtual void run() override;
};

#endif // MYSERVICECLIENTRUNNABLE_H
