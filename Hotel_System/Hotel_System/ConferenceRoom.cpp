#include "ConferenceRoom.h"
#include "Constants.h"

int ConferenceRoom::previous_RoomN_Number = 201;

ConferenceRoom::ConferenceRoom() : Room(PEOPLE_CAPACITY_CONFERENCE_ROOM,INITIAL_PRICE_CONFERENCE_ROOM)
{
    this->setRoomNumber(previous_RoomN_Number++);
}

MyString ConferenceRoom::getType() const
{
    return MyString("Conference Room");
}
