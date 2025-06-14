#include "LuxuryRoom.h"
#include "Constants.h"

int LuxuryRoom::previous_Room_Number = 401;
LuxuryRoom::LuxuryRoom() : Room(PEOPLE_CAPACITY_LUXURY_ROOM,INITIAL_PRICE_LUXURY_ROOM)
{
    this->setRoomNumber(previous_Room_Number);
}

MyString LuxuryRoom::getType() const
{
    return MyString("Luxury Room");
}
