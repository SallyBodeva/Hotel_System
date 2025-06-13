#include "LuxuryRoom.h"
#include "Constants.h"

LuxuryRoom::LuxuryRoom() : Room(PEOPLE_CAPACITY_LUXURY_ROOM,INITIAL_PRICE_LUXURY_ROOM)
{
}

MyString LuxuryRoom::getType() const
{
    return MyString("Luxury Room");
}
