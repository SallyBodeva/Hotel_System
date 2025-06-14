#include "RoomManager.h"

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


//void RoomManager::setDeserializedData(int roomNum, int capacity, Status stat, double initialP, double calcP, const MyVector<Period>& periods)
//{
//}
//
//bool RoomManager::serialize(const char* fileName) const
//{
//	return false;
//}
//
//Room* RoomManager::deserialize(const char* fileName)
//{
//	return nullptr;
//}
