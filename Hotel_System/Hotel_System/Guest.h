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
	MyString getClassificaytin() const;

	int getClientNumber() const;
	const MyVector<Reservation*>& getHistiry() const;

	int getDiscount() const;
	void setClientNumber(int number);
	void setClassification(const Classification& classification);

	static int previousClientNumber;


	bool saveToFile(std::ofstream& file);

	

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

