#include "Room.h"
#include "Apartment.h"
#include "ConferenceRoom.h"
#include "DoubleRoom.h"
#include "LuxuryRoom.h"
#include "SingleRoom.h"

#include <iostream>
#include <fstream>

Room::Room(int peopleCapacity,Status status, double intitialPrice)
{
	if (peopleCapacity <=0)
	{
		throw std::invalid_argument("Invalid people count");
	}
	if (intialPrice < 0)
	{
		throw std::invalid_argument("Invalid intial price");
	}

	this->peopleCapacity = peopleCapacity;
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

void Room::setCalculatedPrice()
{
	this->calculatedPrice = this->calculatePrice(this->intialPrice);
}

double Room::getPrice() const
{
	return this->calculatedPrice;
}

bool Room::getRoomAvailabilityDuringPeriod(const Period& period)const
{
	int vectorSize = periodsTheRoomIsNotAvailable.getSize();

	for (int i = 0; i < vectorSize; i++)
	{
		if (periodsTheRoomIsNotAvailable[i] == period)
		{
			return false;
		}
	}
	return true;
}


const MyString& Room::getStatus() const
{
	switch (status) {
	case Status::Available:
		return MyString("Available");
	case Status::Reserved:
		return MyString("Reserved");
	case Status::UnderRenovation:
		return MyString("UnderRenovation");
	default:
		return MyString("Unknown");
	}
}

int Room::getRoomNumber()const
{
	return this->roomNumber;
}

int Room::getPeopleCapacity() const
{
	return this->peopleCapacity;
}

const MyVector<Period>& Room::getPeriodsTheRoomIsNotAvailable() const
{
	return this->periodsTheRoomIsNotAvailable;
}

void Room::setDeserializedData(int roomNum, int capacity, Status stat, double initialP, double calcP, const MyVector<Period>& periods) {
	this->roomNumber = roomNum;
	this->peopleCapacity = capacity;
	this->status = stat;
	this->intialPrice = initialP;
	this->calculatedPrice = calcP;
	this->periodsTheRoomIsNotAvailable = periods;
}

bool Room::serialize(const char* fileName) const
{
	if (fileName == nullptr)
	{
		return false;
	}

	std::ofstream file(fileName, std::ios::binary, std::ios::app);

	if (!file.is_open())
	{
		return false;
	}

	MyString type = this->getType();
	int lenType = type.getSize();
	file.write(reinterpret_cast<const char*>(&lenType), sizeof(lenType));
	file.write(type.c_str(), lenType);

	int roomNumber = getRoomNumber();

	file.write(reinterpret_cast<const char*>(&roomNumber), sizeof(roomNumber));

	MyString status = this->getStatus();
	int lenStatus = status.getSize();
	file.write(reinterpret_cast<const char*>(&lenStatus), sizeof(lenStatus));
	file.write(status.c_str(), lenStatus);

	int capacity = this->getPeopleCapacity();
	file.write((const char*)&capacity, sizeof(capacity));

	double price = this->getPrice();
	file.write((const char*)&price, sizeof(price));

	int count = this->getPeriodsTheRoomIsNotAvailable().getSize();
	file.write((const char*)&count, sizeof(count));

	for (size_t i = 0; i < count; ++i)
	{
		Period p = this->getPeriodsTheRoomIsNotAvailable()[i];
		p.serialize(file);
	}

	file.close();
	return true;
}

Room* Room::deserialize(const char* fileName) 
{
	if (fileName == nullptr)
	{
		return nullptr;
	}

	std::ifstream file(fileName, std::ios::binary);

	if (!file.is_open())
	{
		return nullptr;
	}

	int lenType;
	file.read(reinterpret_cast<char*>(&lenType), sizeof(lenType));
	char* typeBuffer = new char[lenType + 1];
	file.read(typeBuffer, lenType);
	typeBuffer[lenType] = '\0';
	MyString type(typeBuffer);
	delete[] typeBuffer;

	int roomNumber;
	file.read(reinterpret_cast<char*>(&roomNumber), sizeof(roomNumber));

	int lenStatus;
	file.read(reinterpret_cast<char*>(&lenStatus), sizeof(lenStatus));
	char* statusBuffer = new char[lenStatus + 1];
	file.read(statusBuffer, lenStatus);
	statusBuffer[lenStatus] = '\0';
	MyString statusStr(statusBuffer);
	delete[] statusBuffer;

	Status status;
	if (statusStr == "Available") 
	{
		status = Status::Available;
	}
	else if (statusStr == "Reserved") 
	{
		status = Status::Reserved;
	}
	else if (statusStr == "UnderRenovation") 
	{
		status = Status::UnderRenovation;
	}
	else 
	{
		return nullptr;
	}

	int capacity;
	file.read(reinterpret_cast<char*>(&capacity), sizeof(capacity));

	double initialPrice;
	file.read(reinterpret_cast<char*>(&initialPrice), sizeof(initialPrice));

	double calculatedPrice;
	file.read(reinterpret_cast<char*>(&calculatedPrice), sizeof(calculatedPrice));

	int count;
	file.read(reinterpret_cast<char*>(&count), sizeof(count));

	MyVector<Period> periods;
	for (int i = 0; i < count; ++i) {
		Period p;
		p.deserialize(file); 
		periods.push_back(p);
	}

	Room* room = nullptr;

	if (type == "Apartment")
	{
		room = new Apartment();
	}
	else if (type == "Conference Room")
	{
		room = new ConferenceRoom();
	}
	else if (type == "Double Room")
	{
		room = new DoubleRoom();
	}
	else if (type == "Luxury Room")
	{
		room = new LuxuryRoom();
	}
	else  if (type == "Single Room")
	{
		room = new SingleRoom();
	}
	else
	{
		std::cerr << "Invalid room type";
		return nullptr;
	}

	if (room)
	{
		room->setDeserializedData(roomNumber, capacity, status, initialPrice, calculatedPrice, periods);
	}

	return room;

}
