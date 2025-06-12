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
