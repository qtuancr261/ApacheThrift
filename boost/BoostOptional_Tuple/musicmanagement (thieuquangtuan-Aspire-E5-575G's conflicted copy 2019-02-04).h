#ifndef MUSICMANAGEMENT_H
#define MUSICMANAGEMENT_H

#include <boost/current_function.hpp>
#include <boost/optional.hpp>
#include <boost/random.hpp>
#include <boost/ref.hpp>
#include <boost/tuple/tuple.hpp>
#include <map>
using Collection = std::map<std::string, std::string>;
using CollectionData = std::pair<std::string, std::string>;
using opt_string = boost::optional<std::string>;
using bufferWrapper = boost::tuple<uint8_t*, size_t>;
using boost::cref; // const reference by boost lib
class MusicManagement {
private:
    Collection eventCollection;

public:
    MusicManagement();

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
