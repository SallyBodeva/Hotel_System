#include "SingleRoom.h"
#include "Constants.h"
#include <iostream>
#include <fstream>


SingleRoom::SingleRoom() : Room(PEOPLE_CAPACITY_SINGLE_ROOM,INITIAL_PRICE_SINGLE_ROOM)
{

}

MyString SingleRoom::getType()const
{
    return MyString("Single room");
}
