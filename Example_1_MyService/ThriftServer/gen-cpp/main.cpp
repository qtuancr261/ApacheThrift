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
    //int port = 8888;
    /*shared_ptr<MyServiceHandler> handler(new MyServiceHandler());
    shared_ptr<TProcessor> processor(new MyServiceProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    server.serve();*/

    /*shared_ptr<MyServiceHandler> handler(new MyServiceHandler());
    shared_ptr<TProcessor> processor(new MyServiceProcessor(handler));
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    // using thread pool with maximum 15 threads to handle incoming requests
    shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(15);
    shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
    threadManager->threadFactory(threadFactory);
    threadManager->start();
    TNonblockingServer server(processor, protocolFactory, port, threadManager);
    server.serve();*/
    /*AutoPtr<SimpleFileChannel> pChannel(new SimpleFileChannel);
    pChannel->setProperty("path", "sample.log");
    pChannel->setProperty("rotation", "2 K");
    Logger::root().setChannel(pChannel);
    Logger& logger = Logger::get("TestLogger"); // inherits root channel
    for (int i = 0; i < 100; ++i)
    logger.information("Testing SimpleFileChannel");*/

    MyServerApplication myApp;
    return myApp.run(argc, argv);

    return 0;
}
