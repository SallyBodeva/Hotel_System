#include "DoubleRoom.h"
#include "Constants.h"

DoubleRoom::DoubleRoom() : Room(PEOPLE_CAPACITY_DOUBLE_ROOM,INITIAL_PRICE_DOUBLE_ROOM)
{
}

MyString DoubleRoom::getType() const
{
    return MyString("Double Room");
}
