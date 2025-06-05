#include "Room.h"
#include <iostream>

Room::Room(Status status, double intitialPrice)
{
	if (intialPrice < 0)
	{
		throw std::invalid_argument("Invalid intial price");
	}

	this->status = status;
	this->intialPrice = intitialPrice;
}

Room::~Room()
{
	delete this->pricingStrategy;
}

void Room::setStrategy(PricingStrategy* newStrategy)
{
	delete pricingStrategy;
	this->pricingStrategy = newStrategy;
}

double Room::calculatePrice(double intialPrice)
{
	return this->pricingStrategy->calculatePrice(intialPrice);
}

bool Room::getRoomAvailabilityDuringPeriod(Period period)
{
	return false;
}

MyString Room::getStatus()
{
	return MyString();
}