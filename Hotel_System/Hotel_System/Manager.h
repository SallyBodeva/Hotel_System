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
#include "Room.h"

class Manager : public User{

public:
	Manager() = default;
	Manager(const MyString& username, const MyString& password);

	Role getRole() override;

private:



	// Inherited via User
	MyString getRoleAsSTr() override;

};