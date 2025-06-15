#pragma once
#include "MyString.h"
#include "MyVector.hpp"

class Reservation;

enum class Classification
{
	Regular,
	Gold,
	Platinum
};

class Guest {
public:

	Guest() = default;
	Guest(const MyString& firstName, const MyString& lastName, const MyString& phoneNumber, const MyString& email);
	void setClasification();
	void addNewReservation(Reservation* newReservation);

	int getAllReservationsCount()const;

	MyString getFullName() const;

	int getClientNumber() const;
	const MyVector<Reservation*>& getHistiry() const;

	int getDiscount() const;

	static int previousClientNumber;
private:

	int clientNumber;
	MyString firtsName;
	MyString lastName;
	MyString phoneNumber;
	MyString email;
	Classification classifiication;

	int discoutPercent;

	MyVector <Reservation*> previousReservations;

};

