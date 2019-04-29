#include "myservicehandler.h"

MyServiceHandler::MyServiceHandler()
{
    // Your initialization goes here
}

int64_t MyServiceHandler::send(const std::string &p1, const int32_t p2, const int64_t p3, const std::vector<int32_t> &p4, const std::vector<std::string> &p5, const std::map<std::string, int32_t> &p6)
{
    // Your implementation goes here
    static int64_t count{};
    printf("A client sent: p1 %s - p2 %d - p3 %ld - p4vecSize %ld - p5vecSize %ld - p6mapSize %ld \n", p1.c_str(), p2, p3, p4.size(), p5.size(), p6.size());
    MyData data{};
    data.__set_p1(p1);
    data.__set_p2(p2);
    data.__set_p3(p3);
    data.__set_p4(p4);
    data.__set_p5(p5);
    data.__set_p6(p6);
    // Save the data clent sent into a map
    auto dataWithStr = make_pair(p1, data);
    receivedDataFromClients.insert(dataWithStr);
    return count++;
}

void MyServiceHandler::receive(MyData &_return, const std::string &p1)
{
    // Your implementation goes here
    _return = MyData{};
    try
    {
        _return = receivedDataFromClients.at(p1);
        printf("client has received\n");
    } catch (const exception& excep)
    {
        printf("no matched: %s \n", excep.what());
    }

}

void MyServiceHandler::getData(const std::string &p3)
{
    // Your implementation goes here
    printf("getData\n");
}
