#include "LuxuryRoom.h"
#include "Constants.h"
#include <fstream>

int LuxuryRoom::previous_Room_Number = 401;
LuxuryRoom::LuxuryRoom() : Room(PEOPLE_CAPACITY_LUXURY_ROOM,INITIAL_PRICE_LUXURY_ROOM)
{
    this->setRoomNumber(previous_Room_Number);
}

MyString LuxuryRoom::getType() const
{
    return LUXURY_TYPE;
}

bool LuxuryRoom::saveToFile(std::ofstream& file)
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
