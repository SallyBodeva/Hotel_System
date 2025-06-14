#include "DoubleRoom.h"
#include "Constants.h"

int DoubleRoom::prevoius_Room_Number = 301;

DoubleRoom::DoubleRoom() : Room(PEOPLE_CAPACITY_DOUBLE_ROOM,INITIAL_PRICE_DOUBLE_ROOM)
{
    this->setRoomNumber(prevoius_Room_Number++);
}

MyString DoubleRoom::getType() const
{
    return MyString("Double Room");
}
