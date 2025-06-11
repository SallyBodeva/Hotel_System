#pragma once
#include "MyVector.hpp"
#include "PricingStrategy.h"
#include "MyString.h"
#include "Period.h"

enum class Status
{
	Available,
	Reserved,
	UnderRenovation
};

class Room {
public:

	Room() = default;
	Room(int peopleCapacity, Status status, double intitialPrice);
	virtual ~Room(); 

	void setStrategy(PricingStrategy* newStrategy);
	double calculatePrice(double intialPrice);

	void setCalculatedPrice();
	double getPrice() const;
	double getInitialPrice() const;


	bool isAvailableDuringPeriod(const Period& period) const;

	MyString getStatus() const;

	int getRoomNumber() const ;
	int getPeopleCapacity() const;

	const MyVector<Period>& getPeriodsTheRoomIsNotAvailable() const;


	void setDeserializedData(int roomNum, int capacity, Status stat, double initialP, double calcP, const MyVector<Period>& periods);
	bool serialize(const char* fileName) const;
	Room* deserialize(const char* fileName);


	virtual MyString getType() const = 0;

	
private:
	int roomNumber;
	int peopleCapacity;
	double intialPrice;
	double calculatedPrice;
	Status status;
	PricingStrategy* pricingStrategy;
	bool isAvailable;

	MyVector<Period> periodsTheRoomIsNotAvailable;
};