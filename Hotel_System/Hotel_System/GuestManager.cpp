#include "GuestManager.h"

void GuestManager::addGuest(const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const MyString& email)
{

	Guest g(firstName, lastName, phoneNumber, email);

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
