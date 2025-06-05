#pragma once
#include "Room.h"

class SingleRoom : public Room {
public:
	void serialize() override;
	void deserialize()  override;
};