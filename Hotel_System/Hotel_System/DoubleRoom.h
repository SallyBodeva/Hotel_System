#pragma once
#include "Room.h"

class DoubleRoom : public Room {
public:
	MyString getType()const override;
};