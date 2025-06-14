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

	void saveGuestsToFile();
	void loadGuestsFromFile();

private:

	MyVector<Guest> guests;

};