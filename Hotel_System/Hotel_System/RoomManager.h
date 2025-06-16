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
	

	void free();

	Room* readRoomFromFile(std::ifstream& file);

	bool loadRoomsFromFile();
	bool saveRoomsToFile();

private:

	MyVector <Room*> rooms;

};