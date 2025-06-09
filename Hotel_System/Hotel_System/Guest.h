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

	Guest();
	void setClasification();
	void addNewReservation(Reservation* newReservation);

	int getAllReservationsCount()const;

private:
	MyString clientNumber;
	MyString firtsName;
	MyString lastName;
	MyString phoneNumber;
	MyString email;
	Classification classifiication;


	MyVector <Reservation*> previousReservations;
};