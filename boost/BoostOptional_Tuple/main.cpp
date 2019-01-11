#include "musicmanagement.h"
#include <QCoreApplication>
#include <boost/optional.hpp>
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::string;
int main(int /*argc*/, char* /*argv*/ [])
{
    MusicManagement manager;
    opt_string resultData = manager.findLastDataOfEvent("t_event_1");
    if (resultData) {
        cout << "Lasted data received " << resultData.get() << endl;
    }

    std::map<string, int> eventCollections;
    boost::optional<int> id = manager.findLastDataOfEvent(eventCollections, "Gt");
    if (id) {
        cout << "Lasted id: " << id.get() << endl;
    } else {
        cout << "ID not found " << endl;
    }
    return 0;
}
