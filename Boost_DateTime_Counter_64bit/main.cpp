#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cerr;
using boost::filesystem::exists;
using boost::filesystem::path;
using boost::lexical_cast;
int main(int argc, char *argv[])
{
//    for (int i{}; i < argc; i++)
//        cout << " - " << argv[i] << endl;
//    if (argc < 2)
//    {
//        cerr << "Please use argv[1] as a file name for checking." << endl;
//        return 0;
//    }
//    path filePath{argv[1]};
//    if (exists(filePath))
//        cout << argv[1] << " is exist" << endl;
//    else
//        cerr << argv[1] << " isn't exist" << endl;
//    return 0;
    // string to int - double
    string doubleStr{"3.14"};
    string intStr{"01301220185000000000"};
    // --- use boost lexical cast
    double doubleNum{lexical_cast<double>(doubleStr)};
    int64_t intNum{lexical_cast<int64_t>(intStr)};
    cout << "Result (string to numeric type): " << doubleNum << " | " << intNum << endl;
    cout << "Size " << sizeof (intNum) << " | " << typeid(intNum).name() << endl;

    // int - double to string
    string originalDoubleStr{lexical_cast<string>(doubleNum)};
    string originalIntStr{lexical_cast<string>(intNum)};
    cout << "Result (numeric type to string): " << originalDoubleStr << " | " << originalIntStr << endl;
    cout << "Size " << sizeof (originalIntStr) << " | " << typeid(originalIntStr).name() << endl;
    return 0;
 }
