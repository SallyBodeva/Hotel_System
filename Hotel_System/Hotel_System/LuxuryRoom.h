#pragma once
#include "Room.h"

class LuxuryRoom : public Room {
public:
	MyString getType()const  override;
};