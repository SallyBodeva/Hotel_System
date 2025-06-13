#pragma once
#include "Room.h"

class LuxuryRoom : public Room {
public:
	LuxuryRoom();
	MyString getType()const  override;
};