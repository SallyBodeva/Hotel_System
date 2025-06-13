#include "Guest.h"
#include "Reservation.h"
#include "Constants.h"

Guest::Guest()
{
}

Guest::Guest(const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const MyString& email)
{
	this->firtsName = firstName;
	this->lastName = lastName;
	this->phoneNumber = phoneNumber;
	this->email = email;
	this->classifiication = Classification::Regular;
}

void Guest::setClasification()
{
	int reservationsCount = getAllReservationsCount();

	if (reservationsCount >= MIN_RESERVATIONS_FOR_BEIGN_GOLD)
	{
		this->classifiication = Classification::Gold;
	}
	else if (reservationsCount >= MIN_RESERVATIONS_FOR_BEIGN_PLATINUM)
	{
		this->classifiication = Classification::Platinum;
	}
	else
	{
		this->classifiication = Classification::Regular;
	}
}

void Guest::addNewReservation(Reservation newReservation)
{
		previousReservations.push_back(newReservation);
		setClasification();
}

int Guest::getAllReservationsCount() const
{
	return this->previousReservations.getSize();
}
