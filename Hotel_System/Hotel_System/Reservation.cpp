#include "Reservation.h"

int Reservation::lastReservationId = 1;

Reservation::Reservation(const Guest& guest, const MyVector<Guest>& guests, Room* room, const Period& period) 
{
	this->reservationNumber = lastReservationId++;
	this->mainGuest = guest;
	this->otherGuests = guests;
	this->room = room;
	this->period = period;

	setBill(period);
}

Room* Reservation::getRoom() const
{
	return this->room;
}

const Guest& Reservation::getGuest() const
{
	return this->mainGuest;
}

const Period& Reservation::getPeriod() const
{
	return this->period;
}

int Reservation::getId() const
{
	return this->reservationNumber;
}

void Reservation::setBill(const Period& period)
{
	int nights = period.getNightsCount();
	this->bill = nights * room->getPrice();
}
