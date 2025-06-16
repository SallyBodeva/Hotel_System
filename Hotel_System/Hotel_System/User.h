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

enum class Role
{
	Manager,
	Accountant,
	Receptionist
};

class User {
public:
	User() = default;
	User(const MyString& username, const MyString& password);
	virtual Role getRole() = 0;
	virtual MyString getRoleAsSTr() = 0;
	const MyString& getUsername() const;
	const MyString& getPassword() const;

	virtual ~User() = default;

private:
	int id;
	MyString username;
	MyString password;
};