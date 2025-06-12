#pragma once
#include "User.h"
#include "Room.h"

class Manager : public User{

public:
	Manager() = default;
	Manager(const MyString& username, const MyString& password);
	void addRoom(const Room& room);

	Role getRole() override;

private:


};