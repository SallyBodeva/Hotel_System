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
#include "MyVector.hpp"
#include "Reservation.h"
#include "Guest.h"

class GuestManager {
public:
	GuestManager() = default;
	void addGuest(const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const MyString& email);
	const MyVector<Reservation*>& getGuestHistory(int clientNumber) const;

	Guest getGuestByClientNumber(int number);

	MyString getAllClientsClassifications() const;

	Guest readFromFile(std::ifstream& file);

	Classification getClassificationFromStr(const MyString& type);

	bool loadGuestsFromFile();
	bool saveGuestsToFile();


private:

	MyVector<Guest> guests;

};