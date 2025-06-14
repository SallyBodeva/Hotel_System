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
}
