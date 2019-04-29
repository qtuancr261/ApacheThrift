#ifndef MYSERVICECLONEFACTORY_H
#define MYSERVICECLONEFACTORY_H
#include "MyService.h"
#include "myservicehandler.h"
#include <thrift/transport/TSocket.h>
#include <thrift/TDispatchProcessor.h>
#include <memory>
using ::apache::thrift::transport::TSocket;
using ZTE::MyServiceIfFactory;
using ZTE::MyServiceIf;
using boost::shared_ptr;
using std::dynamic_pointer_cast;
class MyServiceCloneFactory : public MyServiceIfFactory
{
public:
    MyServiceCloneFactory() = default;
    ~MyServiceCloneFactory() override = default;
    virtual MyServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connectionInfo) override;
    virtual void releaseHandler(MyServiceIf* ptrSvIf) override ;
};

#endif // MYSERVICECLONEFACTORY_H
