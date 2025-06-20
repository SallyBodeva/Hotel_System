/**
*
* Solution to course project #5
* Object-Oriented Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2024 / 2025
*
* @author Salihe Ali Bodeva
* @idnumber 9MI0600468
* @compiler VS
*
*
*/



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

struct RoomStatusPeriod 
{
	Period period;
	Status status;
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
	void setInitialPrive(int initialPrice);
	void setRoomNumber(int roomNumber);

	bool isAvailableDuringPeriod(const Period& period) const;

	int getRoomNumber() const ;
	int getPeopleCapacity() const;
	

	void addStatusPeriod(const RoomStatusPeriod& roomStatuPeriod);
	MyVector<RoomStatusPeriod>& getStatusPerids();
	
	void changeStatusPeriodByPeriod(const Period& period);

	virtual MyString getType() const = 0;

	virtual bool saveToFile(std::ofstream& file) = 0;
	
private:

	int roomNumber;
	int peopleCapacity;
	double intialPrice;
	double calculatedPrice;
	PricingStrategy* pricingStrategy;


	MyVector<RoomStatusPeriod> statusPeriods;
};