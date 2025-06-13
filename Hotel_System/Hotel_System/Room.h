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

	Room();
	Room(int peopleCapacity, double intitialPrice);

	Room(const Room&) = delete;
	Room& operator=(const Room&) = delete;


	virtual ~Room(); 

	void setStrategy(PricingStrategy* newStrategy);
	double calculatePrice(double intialPrice);

	void setCalculatedPrice();
	double getPrice() const;
	double getInitialPrice() const;
	void setFree();
	void setStatus(const Status& status);

	bool isAvailableDuringPeriod(const Period& period) const;
	void addNewPeriod(const Period& period);
	void removePeriod(const Period& period);
	MyString getStatus() const;

	int getRoomNumber() const ;
	int getPeopleCapacity() const;

	const MyVector<Period>& getPeriodsTheRoomIsNotAvailable() const;


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