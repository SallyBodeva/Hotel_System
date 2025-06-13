#pragma once
#include "MyString.h"
#include "MyVector.hpp"
#include "ActionLog.h"

class UserManager {
public:

	bool registerUser(const MyString& username, const MyString& password, Role role);
	void login(const MyString& username, const MyString& password);

	//const MyVector<ActionLog>& getLogs() const;
	void printHistory();

private:
	User* loggedUser;
	MyVector<User*> users;
	MyVector<ActionLog> logs;
};