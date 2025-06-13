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