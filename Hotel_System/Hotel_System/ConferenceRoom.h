#pragma once
#include "Room.h"

class ConferenceHall : Room {
public:

	void serialize() override;
	void deserialize()  override;
	MyString getType() override;

private:
};