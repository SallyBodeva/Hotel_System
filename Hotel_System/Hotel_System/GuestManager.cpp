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


#include "GuestManager.h"
#include "Constants.h"
#include <fstream>

void GuestManager::addGuest(const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const MyString& email)
{

	Guest g(firstName, lastName, phoneNumber, email);
	g.setClientNumber(this->guests.getSize()+1);
	this->guests.push_back(g);
}

const MyVector<Reservation*>& GuestManager::getGuestHistory(int clientNumber) const
{
	int guestsCount = guests.getSize();

	for (int i = 0; i < guestsCount; i++)
	{
		if (guests[i].getClientNumber() == clientNumber)
		{
			return guests[i].getHistiry();
		}
	}
}

Guest GuestManager::getGuestByClientNumber(int number)
{
	int guestsCount = guests.getSize();

	for (int i = 0; i < guestsCount; i++)
	{
		if (guests[i].getClientNumber() == number)
		{
			return guests[i];
		}
	}

	throw std::invalid_argument("The user does not exist");
}

MyString GuestManager::getAllClientsClassifications() const
{
	int guestsCount = this->guests.getSize();

	if (guestsCount == 0)
	{
		return MyString("Do not have any clients\n");
	}

	MyString result("Our guests: \n");

	for (int i = 0; i < guestsCount; i++)
	{
		result += "\t";
		result += guests[i].getFullName();
		result += " - ";
		result += guests[i].getClassificaytin();
		result += "\n";
	}

	return result;
}

Guest GuestManager::readFromFile(std::ifstream& file)
{
	if (!file.is_open())
	{
		return Guest();
	}

	MyString clientNumber;
	MyString firstName;
	MyString lastName;
	MyString phoneNumber;
	MyString email;
	MyString classification;
	int discount;

	int reservationCount;

	file >> clientNumber;

	file >> firstName;
	file >> lastName;
	file >> phoneNumber;
	file >> email;

	file >> classification;
	file >> discount;

	Guest guest(firstName, lastName, phoneNumber, email);
	guest.setClientNumber(clientNumber.toInt());
	guest.setClassification(getClassificationFromStr(classification));


	return guest;
}

Classification GuestManager::getClassificationFromStr(const MyString& type)
{
	if (type == "Regular")
	{
		return Classification::Regular;
	}
	else if (type == "Gold")
	{
		return Classification::Gold;
	}
	else if (type == "Platinum")
	{
		return Classification::Platinum;
	}
	return Classification::Regular;

}

bool  GuestManager::loadGuestsFromFile()
{
	std::ifstream guestsFile(GUEST_FILE.c_str());

	if (!guestsFile.is_open())
	{
		return false;
	}

	while (true)
	{
		Guest g = readFromFile(guestsFile);

		if (guestsFile.eof())
		{
			break;
		}

		this->guests.push_back(g);

	}
	return true;
}

bool GuestManager::saveGuestsToFile()
{
	std::ofstream guestsFile(GUEST_FILE.c_str());
	if (!guestsFile.is_open())
	{
		return false;
	}

	for (int i = 0; i < guests.getSize(); ++i)
	{
		guests[i].saveToFile(guestsFile);
	}

	guestsFile.close();
	return true;

}
