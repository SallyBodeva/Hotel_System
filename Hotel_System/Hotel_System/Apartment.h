#pragma once
#include "Room.h"

class Apartment : public Room {
public:
	Apartment();
	MyString getType()const override;

	static int previous_Room_Number;

private:
};