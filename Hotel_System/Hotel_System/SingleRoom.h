#pragma once
#include "Room.h"

class SingleRoom : public Room {
public:

	SingleRoom();
	MyString getType()const  override;
}; 