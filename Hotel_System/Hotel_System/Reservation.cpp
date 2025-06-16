#include "Reservation.h"
#include "Room.h"
#include <fstream>

int Reservation::lastReservationId = 1;

Reservation::Reservation(const Guest& guest,  Room* room, const Period& period) 
{
	this->reservationNumber = lastReservationId++;
	this->mainGuest = guest;
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

void Reservation::addAditionalGuest(const Guest& guest)
{
	this->additionalGuests.push_back(guest);
}

bool Reservation::saveToFile(std::ofstream& file)
{
	if (!file.is_open())
	{
		return false;
	}

	file << this->reservationNumber;
	file << " ";
	file << this->mainGuest.getClientNumber();
	file << " ";
	file << this->room->getRoomNumber();
	file << " ";
	file << this->period.getStartdate().getDate();
	file << " ";
	file << this->period.getEndDate().getDate();
	file << " ";
	file << this->bill;

	file << "\n";

	return true;
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
