#include "SingleRoom.h"
#include <iostream>
#include <fstream>


SingleRoom::SingleRoom(Status status, double initialPrice) : Room(1,status,initialPrice)
{

}

MyString SingleRoom::getType()const
{
    return MyString("Single room");
}
