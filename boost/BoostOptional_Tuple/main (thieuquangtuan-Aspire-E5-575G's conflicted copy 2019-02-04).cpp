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
    cout << BOOST_COMPILER << " " << BOOST_CURRENT_FUNCTION << endl;
    MusicManagement manager;
    std::map<string, int> eventCollections;
    boost::optional<int> id = manager.findLastDataOfEvent(eventCollections, "Gt");
    if (id) {
        cout << "Last data from event " << id.get() << endl;
    }
    return 0;
}
