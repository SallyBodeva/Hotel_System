#pragma once
#include "Room.h"
#include "Guest.h";
#include "Period.h"


class Reservation {
public:
	Reservation();
	Reservation(const Guest& guest, const MyVector<Guest>& guests, Room* room, const Period& period);

private:
	void setBill(int nights);

	Guest mainGuest;
	MyVector<Guest> otherGuests; // валидирай броя на дадените хора и вида на стаята
	Room* room; // динамична памет за менажиране (заради вида)
	Period period; 
	double bill;
};