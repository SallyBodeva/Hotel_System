#pragma once
#include "User.h"
#include "Reservation.h"
#include "Guest.h"
#include "Period.h"

class Receptionist : public User{

public:

	Receptionist() = default;
	Receptionist(const MyString& username, const MyString& password);

	Role getRole() override;

	// Inherited via User
	MyString getRoleAsSTr() override;
};