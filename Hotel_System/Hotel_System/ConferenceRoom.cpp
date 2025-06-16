#include "ConferenceRoom.h"
#include "Constants.h"
#include <fstream>

int ConferenceRoom::prevoius_Room_Number = 201;

ConferenceRoom::ConferenceRoom() : Room(PEOPLE_CAPACITY_CONFERENCE_ROOM,INITIAL_PRICE_CONFERENCE_ROOM)
{
    this->setRoomNumber(prevoius_Room_Number++);
}

MyString ConferenceRoom::getType() const
{
    return CONFERENCE_TYPE;
}

bool ConferenceRoom::saveToFile(std::ofstream& file)
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
