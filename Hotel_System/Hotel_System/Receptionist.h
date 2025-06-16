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
#include "User.h"
#include "Reservation.h"
#include "Guest.h"
#include "Period.h"

class Receptionist : public User{

public:

	Receptionist() = default;
	Receptionist(const MyString& username, const MyString& password);

	Role getRole() override;

	// Inherited via User
	MyString getRoleAsSTr() override;
};