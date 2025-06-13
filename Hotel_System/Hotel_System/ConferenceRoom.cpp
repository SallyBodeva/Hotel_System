#include "ConferenceRoom.h"
#include "Constants.h"

ConferenceRoom::ConferenceRoom() : Room(PEOPLE_CAPACITY_CONFERENCE_ROOM,INITIAL_PRICE_CONFERENCE_ROOM)
{
}

MyString ConferenceRoom::getType() const
{
    return MyString("Conference Room");
}
