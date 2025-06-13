#include "Apartment.h"
#include "Constants.h"

Apartment::Apartment() : Room(PEOPLE_CAPACITY_APARTMENT,INITIAL_PRICE_APARTMENT)
{
}

MyString Apartment::getType() const
{
	return MyString("Apartment");
}
