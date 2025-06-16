#pragma once
#include "Room.h"

class ConferenceRoom : public Room {
public:
	ConferenceRoom();
	MyString getType()const override;

	static int prevoius_Room_Number;
	bool saveToFile(std::ofstream& file) override;
};