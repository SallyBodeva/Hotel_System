#pragma once
#include "MyString.h"
#include "MyVector.hpp"
#include "ActionLog.h"

class UserManager {
public:
	UserManager() = default;
	void seeder();
	bool registerUser(const MyString& username, const MyString& password, Role role);

	User* getUserByUserName(const MyString& username);
	void printHistory();

private:
	User* loggedUser;
	MyVector<User*> users;
	MyVector<ActionLog> logs;
};