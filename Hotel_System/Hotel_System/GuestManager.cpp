#include "GuestManager.h"

void GuestManager::addGuest(const Guest& guest)
{
	this->guests.push_back(guest);
}

const MyVector<Reservation*>& GuestManager::getGuestHistory(const MyString& clientNumber) const
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
