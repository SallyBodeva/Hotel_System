#include "Reservation.h"
#include "Room.h"

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

double Reservation::getBill() const
{
	return this->bill;
}

double Reservation::getDailyBill() const
{
	if (room == nullptr)
	{
		throw std::runtime_error("Room is nullptr...");
	}
	return this->room->getPrice();
}

void Reservation::setBill(const Period& period)
{
	if (room == nullptr)
	{
		throw std::runtime_error("Room is nullptr...");
	}

	int nights = period.getNightsCount();
	this->bill = nights * room->getPrice();

	if (mainGuest.getDiscount() != 0)
	{
		double discountMooney = this->bill * mainGuest.getDiscount();
		this->bill -= discountMooney;
	}

}
