#ifndef MUSICMANAGEMENT_H
#define MUSICMANAGEMENT_H

#include <boost/optional.hpp>
#include <map>
using Collection = std::map<std::string, std::string>;
using CollectionData = std::pair<std::string, std::string>;
using opt_string = boost::optional<std::string>;
class MusicManagement {
private:
    Collection eventCollection;

public:
    MusicManagement();
    opt_string findLastDataOfEvent(const std::string& eventName) const;
};

#endif // MUSICMANAGEMENT_H
