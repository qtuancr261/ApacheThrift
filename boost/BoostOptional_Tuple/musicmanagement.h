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

    template <typename T>
    boost::optional<typename T::mapped_type> findLastDataOfEvent(const T& collection, const typename T::key_type& eventName) const
    {
        typename T::const_iterator iter = collection.find(eventName);
        if (iter != collection.end()) {
            return iter->second;
        }
        return boost::none;
    }
};

#endif // MUSICMANAGEMENT_H
