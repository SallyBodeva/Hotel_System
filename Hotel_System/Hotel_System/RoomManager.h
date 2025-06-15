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

	MyString getAvailableRoomsDurinPeriod(const Period& period);

private:

	MyVector <Room*> rooms;

};