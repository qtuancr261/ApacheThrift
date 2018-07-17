#include "myserviceclientrunnable.h"
std::string MyServiceClientFunction::random_string(size_t length)
{
    auto randchar = []() -> char {
        const char charset[] = "0123456789"
                               "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                               "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    string str(length, 0);
    std::generate_n(str.begin(), length, randchar);
    return str;
}

void MyServiceClientFunction::generateMyData(MyData &preparedData, size_t p1Size)
{
    preparedData.__set_p1(random_string(p1Size));
    preparedData.__set_p2(random_int<int32_t>(100));
    preparedData.__set_p3(random_int<int64_t>(5000));

    vector<int32_t> preparedI32Vector{random_int<int32_t>(100), 10};
    preparedData.__set_p4(preparedI32Vector);

    vector<string> preparedStrVector{random_string(4), random_string(4), random_string(4)};
    preparedData.__set_p5(preparedStrVector);

    map<string, int32_t> preparedMap{{random_string(4), random_int<int32_t>(10)}, {random_string(4), random_int<int32_t>(10)}, {random_string(4), random_int<int32_t>(10)}};
    preparedData.__set_p6(preparedMap);
}

void MyServiceClientRunnable::run()
{
    // A Transport layer that uses a blocking socket, only one connection can be active at a time
    shared_ptr<TSocket> socket(new TSocket("localhost", 9090));
    // Others transports are often wrapped around in this one, it provides buffering of input and output data
    shared_ptr<TTransport> transport(new TFramedTransport(socket));

    shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    // Start
    transport->open();
    MyServiceClient client(protocol);
    MyData data1;
    MyServiceClientFunction::generateMyData(data1, 4);
    printf("send(%ld)\n",client.send(data1.p1, data1.p2, data1.p3, data1.p4, data1.p5, data1.p6));
    MyData data2;
    MyServiceClientFunction::generateMyData(data2, 5);
    printf("send(%ld)\n",client.send(data2.p1, data2.p2, data2.p3, data2.p4, data2.p5, data2.p6));

    MyData recvData;
    client.receive(recvData, data1.p1);
    if (recvData == data1)
        printf("matched send and receive data\n");
    else
        printf("mo matched\n");
    transport->close();
}
