#include "ReservationManager.h"

Reservation ReservationManager::createReservation(const Guest& guest, Room* room, const Period& period)
{
	if (room == nullptr)
	{
		throw std::invalid_argument("Invalid room!\n");
	}

	if (!(room->isAvailableDuringPeriod(period)))
	{
		throw std::invalid_argument("Room not available for the requested period.\n");
	}

	Reservation r(guest, room, period);

	RoomStatusPeriod sp;
	sp.period = period;
	sp.status = Status::Reserved;

	room->addStatusPeriod(sp);

	this->reservations.push_back(r);
	return r;
}

bool ReservationManager::deleteReservation(int id)
{
	int reservationsCount = this->reservations.getSize();

	if (id < 0 || id > reservationsCount)
	{
		return false;
	}

	for (size_t i = 0; i < reservationsCount; i++)
	{

		if (reservations[i].getId() == id)
		{
			reservations[i].getRoom()->changeStatusPeriodByPeriod(reservations[i].getPeriod());
			reservations.removeAt(i);
			return true;
		}
	}

	std::cout << reservations.getSize();

	return false;
}

void ReservationManager::addAdditionalGuests(int reservationNumber, const Guest& guest)
{
	int count = this->reservations.getSize();

	for (int i = 0; i < count; i++)
	{
		if (this->reservations[i].getId() == reservationNumber)
		{
			reservations[i].addAditionalGuest(guest);
		}
	}
}

MyString ReservationManager::getCurrentReservations()
{

	int count = reservations.getSize();

	MyString result("Current reservations: \n");

	if (count == 0)
	{
		MyString str("No reservations at this period...");
		return str;
	}


	for (int i = 0; i < count; i++)
	{
		result += '\t';
		result += reservations[i].getGuest().getFullName();
		result += " ";

		int number = reservations[i].getRoom()->getRoomNumber();
		result += MyString::toStr(number);

		result += '\n';
	}

	return result;
}

const MyVector<Reservation>& ReservationManager::getAllReservations() const
{
	return this->reservations;
}

