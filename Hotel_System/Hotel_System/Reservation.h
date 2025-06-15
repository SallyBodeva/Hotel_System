#pragma once
#include "Guest.h"
#include "Period.h"

class Room;

class Reservation {
public:
	Reservation() = default ;
	Reservation(const Guest& guest, Room* room, const Period& period);

	Room* getRoom() const;
	const Guest& getGuest()const;
	const Period& getPeriod() const;
	int getId() const;
	double getBill() const; 
	double getDailyBill() const;

	void addAditionalGuest(const Guest& guest);

private:
	void setBill(const Period& period);

	int reservationNumber;
	Guest mainGuest;
	MyVector<Guest> additionalGuests; // валидирай броя на дадените хора и вида на стаята
	Room* room; // динамична памет за менажиране (заради вида)
	Period period; 
	double bill;

	static int lastReservationId;
};
