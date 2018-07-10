#include "gen-cpp/MyService.h"
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <iostream>
#include <memory>
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace std;
// from MyService
using namespace ThriftTest;

int main(int argc, char* argv[])
{
    for (int index{}; index < argc; ++index)
        cout << argv[index] << endl;
    shared_ptr<TSocket> socket {make_shared<TSocket>("localhost", 9090)};
    shared_ptr<TTransport> transport{make_shared<TBufferedTransport>(socket)};
    shared_ptr<TProtocol> protocol{make_shared<TBinaryProtocol>(transport)};

    MyServiceClient client(protocol);
    transport->open();
    client.ping();
    cout << "Let's ping the server" << endl;
    cin.get();
    transport->close();
    return 0;
}
