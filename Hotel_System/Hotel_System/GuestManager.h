#pragma once
#include "MyVector.hpp"
#include "Reservation.h"
#include "Guest.h"

class GuestManager {
public:
	GuestManager() = default;
	void addGuest(const Guest& guest);
	const MyVector<Reservation*>& getGuestHistory(const MyString& clientNumber) const;

	void saveGuestsToFile();
	void loadGuestsFromFile();

private:

	MyVector<Guest> guests;

};