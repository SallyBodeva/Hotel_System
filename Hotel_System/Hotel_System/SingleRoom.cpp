#include "SingleRoom.h"
#include "Constants.h"
#include <iostream>
#include <fstream>

int SingleRoom::previous_Room_Number = 501;

SingleRoom::SingleRoom() : Room(PEOPLE_CAPACITY_SINGLE_ROOM,INITIAL_PRICE_SINGLE_ROOM)
{
    this->setRoomNumber(previous_Room_Number++);
}

MyString SingleRoom::getType()const
{
	return SINGLE_TYPE;
}

bool SingleRoom::saveToFile(std::ofstream& file)
{
	if (!file.is_open())
	{
		return false;
	}

	file << this->getType();
	file << " ";
	file << this->getRoomNumber();

	file << "\n";

	return true;
}
