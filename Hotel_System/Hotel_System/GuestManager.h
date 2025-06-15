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