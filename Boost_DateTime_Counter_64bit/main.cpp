#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/date_time.hpp>
#include <cassert>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cerr;
using boost::filesystem::exists;
using boost::filesystem::path;
using boost::lexical_cast;
namespace bgreg = boost::gregorian;
namespace bposixtime = boost::posix_time;
void getCurrentTimeByHour(int64_t& result, int64_t& currentCounter)
{
    // Working with date
    static bposixtime::ptime posixRefTime = bposixtime::second_clock::local_time();
    bgreg::date today = bgreg::day_clock::local_day();
    bgreg::date passedDay(2018, bgreg::Aug, 10);
    bgreg::date_duration dateDiff = today - passedDay;
    //cout << "today is : " << today.day_of_week() << " " << today.day() << " ."  << today.month() << endl;
    //cout << "date duration from today to passed day: " << dateDiff.days() << endl;
    // Working with Posix time
    bposixtime::ptime posixCurrentTime = bposixtime::second_clock::local_time();

    bposixtime::time_duration posixDuration = posixCurrentTime - posixRefTime;
    //cout << "DIFF : " << posixDuration.hours() << endl;
    int64_t diff = posixDuration.hours();
    cout << "DIFF :" << diff << endl;

    string counterHours{lexical_cast<string>(posixDuration.hours())};
    string counterHoursLength{lexical_cast<string>(counterHours.length())};
    string counterStr{lexical_cast<string>(currentCounter)};
    string resultStr = string("").append(counterHoursLength).append(counterHours).append(counterStr);
    result = lexical_cast<int64_t>(resultStr);
    string refTimeStr = lexical_cast<string>(posixRefTime);
    cout << "Ref Time: " << refTimeStr << " | Current time: " << posixCurrentTime << endl;
    ++currentCounter;
}
void gnext(int64_t& result, const string& key, int64_t& currentCounter)
{
    getCurrentTimeByHour(result, currentCounter);
    cout << "gnext : " << result << endl;
}
int main(int argc, char *argv[])
{
    int a = 0;
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
    // Test daytime with boost
    int64_t result = 0;
    int64_t currentCounter = 10000;
    while (true)
        gnext(result, "GTK", currentCounter);
    string exampleCounterWithTime{"6876000999999999999"};
    size_t timeLength{lexical_cast<size_t>(exampleCounterWithTime.at(0))};
    size_t counterLength{exampleCounterWithTime.size() - timeLength};
    //cout << exampleCounterWithTime.substr(1, timeLength) << endl;
    //cout << exampleCounterWithTime.substr(timeLength + 1, counterLength) << endl;
    return 0;
 }
