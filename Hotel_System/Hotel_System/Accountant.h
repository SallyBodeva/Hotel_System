/**
*
* Solution to course project #5
* Object-Oriented Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2024 / 2025
*
* @author Salihe Ali Bodeva
* @idnumber 9MI0600468
* @compiler VS
*
*
*/



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