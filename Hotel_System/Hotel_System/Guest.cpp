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
		this->discoutPercent = DISCOUNT_PERCENT_FOR_GOLD;
	}
	else if (reservationsCount >= MIN_RESERVATIONS_FOR_BEIGN_PLATINUM)
	{
		this->classifiication = Classification::Platinum;
		this->discoutPercent = DISCOUNT_PERCENT_FOR_PLATINUM;
	}
	else
	{
		this->classifiication = Classification::Regular;
		this->discoutPercent = 0;
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

const MyString& Guest::getClientNumber() const
{
	return this->clientNumber;
}

const MyVector<Reservation>& Guest::getHistiry() const
{
	return this->previousReservations;
}

int Guest::getDiscount() const
{
	return this->discoutPercent;;
}
