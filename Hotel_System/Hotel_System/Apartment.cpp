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



#include "Apartment.h"
#include "Constants.h"
#include <fstream>

int Apartment::prevoius_Room_Number = 101;

Apartment::Apartment() : Room(PEOPLE_CAPACITY_APARTMENT,INITIAL_PRICE_APARTMENT)
{
	this->setRoomNumber(prevoius_Room_Number++);
}

MyString Apartment::getType() const
{
	return APARTMENT_TYPE;
}

bool Apartment::saveToFile(std::ofstream& file)
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
