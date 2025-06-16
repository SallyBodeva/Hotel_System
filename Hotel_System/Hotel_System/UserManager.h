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