#include "musicmanagement.h"

MusicManagement::MusicManagement()
    : eventCollection{ CollectionData{ "t_event_1", "A" }, CollectionData{ "t_event_2", "B" } }
{
}

opt_string MusicManagement::findLastDataOfEvent(const std::string& eventName) const
{
    Collection::const_iterator iter{ eventCollection.find(eventName) };
    if (iter != eventCollection.end()) {
        return iter->second;
    }
    return boost::none;
}
