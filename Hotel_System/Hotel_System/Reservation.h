#pragma once
#include "Room.h"
#include "Guest.h";
#include "Period.h"

class Reservation {
public:

	void createReservation();
	void addReservationToGuests(MyVector<Guest>& guests);
	void deleteReservation();

private:
	MyVector<Guest> guests; // валидирай броя на дадените хора и вида на стаята
	Room* room; // динамична памет за менажиране
	Period period; 
};