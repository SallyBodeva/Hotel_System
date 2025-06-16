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

#include "ReservationManager.h"
#include <fstream>

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

//Reservation ReservationManager::readFromFile(std::ifstream& file)
//{
//	if (!file.is_open())
//	{
//		return Reservation();
//	}
//
//	int reservationNumber;
//	int mainGuestNumber;
//	int roomNumber;
//	MyString startDate;
//	MyString endDate;
//	double bill;
//
//	file >> reservationNumber;
//	file >> mainGuestNumber;
//	file >> roomNumber;
//	file >> startDate;
//	file >> endDate;
//	file >> bill;
//
//
//	int startDay = startDate.substr(0, 2).toInt();
//	int startMonth = startDate.substr(3, 2).toInt();
//	int startyear = startDate.substr(6, 4).toInt();
//
//	int endDay = endDate.substr(0, 2).toInt();
//	int endMonth = endDate.substr(3, 2).toInt();
//	int endyear = endDate.substr(6, 4).toInt();
//
//
//}
//
