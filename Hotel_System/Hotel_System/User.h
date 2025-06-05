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


private:
	int id;
	MyString username;
	MyString password;
};