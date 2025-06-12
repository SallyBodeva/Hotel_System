#include "ReservationManager.h"

Reservation ReservationManager::createReservation(const Guest& guest, const MyVector<Guest>& guests,  Room* room, const Period& period)
{
	if (room == nullptr)
	{
		throw std::invalid_argument("Invalid room!");
	}

	if (!(room->isAvailableDuringPeriod(period)))
	{
		throw std::runtime_error("Room not available for the requested period.");
	}

	if (room->getPeopleCapacity() > (guests.getSize() + 1))
	{
		throw std::invalid_argument("The room is not big enough for that reservation!");
	}

	Reservation r(guest, guests, room, period);
	room->addNewPeriod(period);
	this->reservations.push_back(r);
	return r;
}

bool ReservationManager::deleteReservation(int id)
{
	int reservationsCount = this->reservations.getSize();

	if (id < 0 || id >= reservationsCount)
	{
		return false;
	}

	for (size_t i = 0; i < reservationsCount; i++)
	{
		if (reservations[i].getId() == id)
		{
			reservations[i].getRoom()->setFree();
			reservations[i].getRoom()->removePeriod(reservations[i].getPeriod());
			reservations.removeAt(i);
			return true;
		}
	}

	return false;
}

const MyVector<Reservation>& ReservationManager::getAllReservations() const
{
	return this->reservations;
}

