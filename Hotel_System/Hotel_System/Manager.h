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