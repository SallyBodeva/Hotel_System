#pragma once
#include "Room.h"

class SingleRoom : public Room {
public:

	SingleRoom() = default;
	SingleRoom(Status status, double initialPrice);
	MyString getType()const  override;
}; 