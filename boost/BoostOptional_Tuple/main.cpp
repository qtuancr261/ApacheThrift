#include "musicmanagement.h"
#include <QCoreApplication>
#include <boost/optional.hpp>
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
//typedef map<string, string> ArtisteAlbumMap;
//ArtisteAlbumMap zingMp3_Collections;
//// Version 1
//string findLastestAlbumOf_V1(const string& artiste)
//{
//    auto iter = zingMp3_Collections.find(artiste);
//    if (iter != zingMp3_Collections.end()) {
//        return iter->second;
//    }
//    return " ";
//}

//// Version 2
//boost::optional<string> findLastestAlbumOf_V2(const string& artiste)
//{
//    auto iter = zingMp3_Collections.find(artiste);
//    if (iter != zingMp3_Collections.end()) {
//        return iter->second;
//    }
//    return boost::none;
//}
int main(int /*argc*/, char* /*argv*/ [])
{
    //    zingMp3_Collections.insert(pair<string, string>("D14CQCP01-N", "2014"));
    //    zingMp3_Collections.insert(pair<string, string>("D14CQPT01-N", "2014"));
    //    // This case, our function will return an empty string
    //    // inserted The return string is ambiguous
    //    cout << findLastestAlbumOf_V1("D14CQKT01-N") << endl;
    //    zingMp3_Collections.insert(pair<string, string>("D19CQCP01-N", ""));
    //    cout << findLastestAlbumOf_V1("D19CQCP01-N") << endl;

    //    // Boost utilities
    //    boost::optional<string> result{ findLastestAlbumOf_V2("D19CQCP01-N") };
    //    if (result) {
    //        result.get_value_or("GTJ");
    //        cout << "Found it: " << result.get() << endl;
    //        if (result->empty())
    //            cout << "Result is untitled" << result.get() << endl;
    //    }

    MusicManagement manager;
    opt_string resultData = manager.findLastDataOfEvent("t_event_1");
    if (resultData) {
        cout << "Lasted data received " << resultData.get() << endl;
    }
    return 0;
}
