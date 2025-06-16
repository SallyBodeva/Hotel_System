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


#include "User.h"

User::User(const MyString& username, const MyString& password)
{
	if (username.empty())
	{
		throw std::invalid_argument("Invalid username");
	}

	if (password.empty())
	{
		throw std::invalid_argument("Invalid password");
	}
	this->username = username;
	this->password = password;
}

const MyString& User::getUsername() const
{
	return this->username;
}

const MyString& User::getPassword() const
{
	return this->password;
}
