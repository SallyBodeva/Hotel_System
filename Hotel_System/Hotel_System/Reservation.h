#pragma once
#include "Room.h"
#include "Guest.h";
#include "Period.h"


class Reservation {
public:



private:
	Guest mainGuest;
	MyVector<Guest> otherGuests; // валидирай броя на дадените хора и вида на стаята
	Room* room; // динамична памет за менажиране (заради вида)
	Period period; 
};