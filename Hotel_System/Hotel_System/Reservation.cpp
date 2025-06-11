#include "Reservation.h"

Reservation::Reservation(const Guest& guest, const MyVector<Guest>& guests, Room* room, const Period& period) 
{
	this->mainGuest = guest;
	this->otherGuests = guests;
	this->room = room;
	this->period = period;
}

void Reservation::setBill(int nights)
{
	this->bill = nights * room->getPrice();
}
