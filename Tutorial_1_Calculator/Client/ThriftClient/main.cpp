#include <iostream>
#include <thrift/protocol/TBinaryProtocol.h>
using namespace std;
int main(int argc, char *argv[])
{
    for (int index{}; index < argc; ++index)
        cout << argv[index] << endl;

    return 0;
}
