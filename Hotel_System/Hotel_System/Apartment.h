#pragma once
#include "Room.h"

class Apartment : public Room {
public:
	Apartment();
	MyString getType()const override;
	bool saveToFile(std::ofstream& file) override;

	static int prevoius_Room_Number;
private:
};