#pragma once
#include "MyVector.hpp"
#include "Period.h"
#include "Room.h"
#include "Apartment.h"
#include "ConferenceRoom.h"
#include "DoubleRoom.h"
#include "LuxuryRoom.h"
#include "SingleRoom.h"

class RoomManager {
public:
	RoomManager() = default;
	void addRoom(Room* room);
	Room* getRoomByNumber(int roomNumber);

	//MyString getAvailableRooms();

	/*void setDeserializedData(int roomNum, int capacity, Status stat, double initialP, double calcP, const MyVector<Period>& periods);
	bool serialize(const char* fileName) const;
	Room* deserialize(const char* fileName);*/

private:

	MyVector <Room*> rooms;

};