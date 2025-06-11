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

	int nights = period.getNightsCount();

	//r.setBill(nights);

	return r;

}

bool ReservationManager::deleteReservation()
{
    return false;
}
