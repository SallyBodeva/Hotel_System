/**
*
* Solution to course project #5
* Object-Oriented Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2024 / 2025
*
* @author Salihe Ali Bodeva
* @idnumber 9MI0600468
* @compiler VS
*
*
*/


#include "DoubleRoom.h"
#include "Constants.h"
#include <fstream>

int DoubleRoom::prevoius_Room_Number = 301;

DoubleRoom::DoubleRoom() : Room(PEOPLE_CAPACITY_DOUBLE_ROOM,INITIAL_PRICE_DOUBLE_ROOM)
{
    this->setRoomNumber(prevoius_Room_Number++);
}

MyString DoubleRoom::getType() const
{
    return DOUBLE_TYPE;
}

bool DoubleRoom::saveToFile(std::ofstream& file)
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
