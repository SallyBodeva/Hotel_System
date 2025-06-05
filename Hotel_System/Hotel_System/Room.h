#pragma once
#include "PricingStrategy.h"
#include "MyString.h"

enum class Status
{
	Available,
	Reserved,
	UnderRenovation
};

class Room {
public:

	Room() = default;
	Room(Status status, double intitialPrice);
	virtual ~Room();

	void setStrategy(PricingStrategy* newStrategy);
	double calculatePrice(double intialPrice);

	MyString getStatus(); 

	virtual void serialize() = 0;
	virtual void deserialize() = 0;

private:
	int roomNumber;
	double intialPrice;
	Status status;
	PricingStrategy* pricingStrategy;
};