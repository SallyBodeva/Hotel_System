#pragma once
#include "Room.h"

class DoubleRoom : public Room {
public:
	DoubleRoom();
	MyString getType()const override;
};