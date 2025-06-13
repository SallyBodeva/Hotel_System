#pragma once
#include "Reservation.h"
#include "User.h"
#include "Period.h"
#include "MyVector.hpp"

class Accountant : public User{
public:
	

    Accountant() = default;
    Accountant(const MyString& username, const MyString& password);
    Role getRole() override;

private:


    // Inherited via User
    MyString getRoleAsSTr() override;

};