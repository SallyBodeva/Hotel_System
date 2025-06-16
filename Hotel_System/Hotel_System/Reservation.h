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


	bool saveToFile(std::ofstream& file);

private:
	void setBill(const Period& period);

	int reservationNumber;
	Guest mainGuest;
	MyVector<Guest> additionalGuests; 
	Room* room; 
	Period period; 
	double bill;

	static int lastReservationId;
};
