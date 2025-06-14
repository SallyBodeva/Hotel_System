#pragma once
#include "Room.h"

class LuxuryRoom : public Room {
public:
	LuxuryRoom();
	MyString getType()const  override;
	static int previous_Room_Number;
};