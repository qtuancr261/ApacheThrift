#include "musicmanagement.h"

MusicManagement::MusicManagement()
    : eventCollection{ CollectionData{ "t_event_1", "A" }, CollectionData{ "t_event_2", "B" } }
{
    std::cout << "-" << BOOST_CURRENT_FUNCTION << std::endl;
}
