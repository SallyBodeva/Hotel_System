#pragma once
#include "Room.h"

class LuxuryRoom : Room {
public:

	void serialize() override;
	void deserialize()  override;
	MyString getType() override;
};