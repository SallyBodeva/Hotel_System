#include "Room.h"
#include <iostream>
#include <fstream>
#include "RoomFactory.h"

Room::Room() : pricingStrategy(nullptr), roomNumber(0), peopleCapacity(0), intialPrice(0.0), calculatedPrice(0.0), isAvailable(true)
{
}

Room::Room(int peopleCapacity, double intitialPrice)
{
	if (peopleCapacity <= 0)
	{
		throw std::invalid_argument("Invalid people count");
	}
	if (intialPrice < 0)
	{
		throw std::invalid_argument("Invalid intial price");
	}
	PricingStrategy* basic = new BasicPricing();
	this->setStrategy(basic);
	this->peopleCapacity = peopleCapacity;
	this->intialPrice = intitialPrice;
	this->isAvailable = true;

	setCalculatedPrice();
}

Room::~Room()
{
	delete this->pricingStrategy;
}

void Room::setStrategy(PricingStrategy* newStrategy)
{
	if (newStrategy == nullptr)
	{
		throw std::runtime_error("Strategy is nullpr...");
	}
	delete pricingStrategy;
	this->pricingStrategy = newStrategy;
}

double Room::calculatePrice(double intialPrice)
{
	return this->pricingStrategy->calculatePrice(intialPrice);
}

void Room::setCalculatedPrice()
{
	this->calculatedPrice = this->calculatePrice(this->intialPrice);
}

double Room::getPrice() const
{
	return this->calculatedPrice;
}

double Room::getInitialPrice() const
{
	return this->intialPrice;
}


void Room::setRoomNumber(int roomNumber)
{
	this->roomNumber = roomNumber;
}

bool Room::isAvailableDuringPeriod(const Period& period)const
{
	int count = this->statusPeriods.getSize();

	if (count == 0)
	{
		return true;
	}

	for (int i = 0; i < count; i++)
	{
		if (statusPeriods[i].period == period && statusPeriods[i].status != Status::Reserved)
		{
			return true;
		}
	}
	return false;
}


int Room::getRoomNumber()const
{
	return this->roomNumber;
}

int Room::getPeopleCapacity() const
{
	return this->peopleCapacity;
}
void Room::addStatusPeriod(const RoomStatusPeriod& roomStatuPeriod)
{
	this->statusPeriods.push_back(roomStatuPeriod);
}
MyVector<RoomStatusPeriod>& Room::getStatusPerids()
{
	return this->statusPeriods;
}

void Room::changeStatusPeriodByPeriod(const Period& period)
{
	int count = statusPeriods.getSize();

	for (int i = 0; i < count; i++)
	{
		if (statusPeriods[i].period == period)
		{
			statusPeriods[i].status = Status::Available;
		}
	}
}

