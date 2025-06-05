#pragma once
#include "Room.h"

class DoubleRoom : public Room {
public:

	void serialize() override;
	void deserialize()  override;
};