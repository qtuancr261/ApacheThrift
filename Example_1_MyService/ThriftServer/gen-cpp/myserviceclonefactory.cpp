#include "myserviceclonefactory.h"


ZTE::MyServiceIf *MyServiceCloneFactory::getHandler(const apache::thrift::TConnectionInfo &connectionInfo)
{
        shared_ptr<TSocket> sock = dynamic_pointer_cast<TSocket>(connectionInfo.transport);
        cout << "Incoming connection\n";
        cout << "\tSocketInfo: "  << sock->getSocketInfo() << "\n";
        cout << "\tPeerHost: "    << sock->getPeerHost() << "\n";
        cout << "\tPeerAddress: " << sock->getPeerAddress() << "\n";
        cout << "\tPeerPort: "    << sock->getPeerPort() << "\n";
        return new MyServiceHandler;
}

void MyServiceCloneFactory::releaseHandler(MyServiceIf *ptrSvIf)
{
    delete  ptrSvIf;
}
