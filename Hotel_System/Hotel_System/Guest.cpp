#include "Guest.h"
#include "Reservation.h"
#include "Constants.h"
#include <fstream>

int Guest::previousClientNumber = 1;

Guest::Guest(const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const MyString& email)
{
	this->firtsName = firstName;
	this->lastName = lastName;
	this->phoneNumber = phoneNumber;
	this->email = email;
	this->classifiication = Classification::Regular;
	this->clientNumber = previousClientNumber++;
}

void Guest::setClasification()
{
	int reservationsCount = getAllReservationsCount();


	if (reservationsCount >= MIN_RESERVATIONS_FOR_BEIGN_PLATINUM)
	{
		this->classifiication = Classification::Gold;
		this->discoutPercent = DISCOUNT_PERCENT_FOR_GOLD;
	}
	else if (reservationsCount >= MIN_RESERVATIONS_FOR_BEIGN_GOLD)
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

void Guest::addNewReservation(Reservation* newReservation)
{
	previousReservations.push_back(newReservation);
	setClasification();
}

int Guest::getAllReservationsCount() const
{
	return this->previousReservations.getSize();
}

MyString Guest::getFullName() const
{
	MyString result(this->firtsName);
	result += " ";
	result += this->lastName;

	return result;
}

MyString Guest::getClassificaytin() const
{
	MyString result;

	switch (this->classifiication)
	{
	case Classification::Regular:
		result = "Regular";
		break;
	case Classification::Gold:
		result = "Gold";
		break;
	case Classification::Platinum:
		result = "Platinum";
		break;

	default:
		result = "Invalid";
		break;
	}

	return result;
}

int Guest::getClientNumber() const
{
	return this->clientNumber;
}

const MyVector<Reservation*>& Guest::getHistiry() const
{
	return this->previousReservations;
}

int Guest::getDiscount() const
{
	return this->discoutPercent;;
}

void Guest::setClientNumber(int number)
{
	this->clientNumber = number;
}

void Guest::setClassification(const Classification& classification)
{
	this->classifiication = classification;
}

bool Guest::saveToFile(std::ofstream& file)
{
	if (!file.is_open())
	{
		return false;
	}

	file << this->clientNumber;
	file << " ";
	file << this->firtsName;
	file << " ";
	file << this->lastName;
	file << " ";
	file << this->phoneNumber;
	file << " ";
	file << this->email;
	file << " ";
	file << this->getClassificaytin();
	file << " ";
	file << this->discoutPercent;
	file << "\n";

	return true;

}

