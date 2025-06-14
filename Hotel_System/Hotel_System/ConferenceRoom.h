#pragma once
#include "Room.h"

class ConferenceRoom : public Room {
public:
	ConferenceRoom();
	MyString getType()const override;

	static int previous_RoomN_Number;

private:
};