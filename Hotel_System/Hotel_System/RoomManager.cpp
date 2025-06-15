#include "RoomManager.h"
#include <sstream>

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

	return result;
}
