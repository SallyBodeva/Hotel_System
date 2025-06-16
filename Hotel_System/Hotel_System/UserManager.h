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
#include "MyString.h"
#include "MyVector.hpp"

class UserManager {
public:
	UserManager() = default;
	void seeder();
	bool registerUser(const MyString& username, const MyString& password, Role role);

	User* getUserByUserName(const MyString& username);

	void free();

private:
	User* loggedUser;
	MyVector<User*> users;
};