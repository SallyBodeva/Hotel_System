/**
*
* Solution to course project #5
* Object-Oriented Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2024 / 2025
*
* @author Salihe Ali Bodeva
* @idnumber 9MI0600468
* @compiler VS
*
*
*/

#pragma once
#include "Room.h"

class DoubleRoom : public Room {
public:
	DoubleRoom();
	MyString getType()const override;

	static int prevoius_Room_Number;
	bool saveToFile(std::ofstream& file) override;
};