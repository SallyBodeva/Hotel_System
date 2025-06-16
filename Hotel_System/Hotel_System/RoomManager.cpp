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

#include "RoomManager.h"
#include <sstream>
#include <fstream>
#include "RoomFactory.h"
#include "Constants.h"

void RoomManager::addRoom(Room* room)
{
	if (room != nullptr)
	{
		this->rooms.push_back(room);
	}
}

Room* RoomManager::getRoomByNumber(int roomNumber)
{
	int roomsCount = rooms.getSize();

	for (int i = 0; i < roomsCount; i++)
	{
		if (rooms[i]->getRoomNumber() == roomNumber)
		{
			return rooms[i];
		}
	}
	return nullptr;
}

MyString RoomManager::getAvailableRoomsDurinPeriod(const Period& period)
{
	MyString result("Available rooms numbers: ");

	int count = this->rooms.getSize();

	for (int i = 0; i < count; i++)
	{
		if (rooms[i]->isAvailableDuringPeriod(period))
		{
			int number = rooms[i]->getRoomNumber();
			result += MyString::toStr(number);
			result += " ";
		}
	}
	result += "\n";

	return result;
}

void RoomManager::free()
{
	int roomsCount = this->rooms.getSize();

	for (int i = 0; i < roomsCount; i++)
	{
		delete rooms[i];
	}
}

Room* RoomManager::readRoomFromFile(std::ifstream& file)
{
	if (!file.is_open())
	{
		return nullptr;
	}

	MyString type;
	int number;
	
	file >> type;
	file >> number;

	Room* room = RoomFactory::createRoomByType(type);
	if (room == nullptr)
	{
		return nullptr;
	}
	room->setRoomNumber(number);

	return room;
}

bool RoomManager::loadRoomsFromFile()
{
	std::ifstream roomsFile(ROOM_FILE.c_str());

	if (!roomsFile.is_open())
	{
		return false;
	}

	while (true)
	{
		Room* room = readRoomFromFile(roomsFile);

		if (room == nullptr)
		{
			break;
		}

		if (roomsFile.eof())
		{
			break;
		}

		this->rooms.push_back(room);
	}
	return true;
}

bool RoomManager::saveRoomsToFile()
{
	std::ofstream roomsFile(ROOM_FILE.c_str());
	if (!roomsFile.is_open())
	{
		return false;
	}

	for (int i = 0; i < rooms.getSize(); ++i)
	{
		rooms[i]->saveToFile(roomsFile);
	}

	roomsFile.close();
	return true;
}
