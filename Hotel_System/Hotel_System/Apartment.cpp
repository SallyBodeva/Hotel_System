#include "Apartment.h"
#include "Constants.h"

int Apartment::previous_Room_Number = 101;

Apartment::Apartment() : Room(PEOPLE_CAPACITY_APARTMENT,INITIAL_PRICE_APARTMENT)
{
	this->setRoomNumber(previous_Room_Number++);
}

MyString Apartment::getType() const
{
	return MyString("Apartment");
}
