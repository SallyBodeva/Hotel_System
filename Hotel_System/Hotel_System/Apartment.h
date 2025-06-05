#pragma once
#include "Room.h"

class Appartment : Room {
public:

	void serialize() override;
	void deserialize() override;

private:

};