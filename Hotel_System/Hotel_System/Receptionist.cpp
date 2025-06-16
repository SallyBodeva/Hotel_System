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


#include "Receptionist.h"

Receptionist::Receptionist(const MyString& username, const MyString& password):User(username,password)
{
}

Role Receptionist::getRole()
{
    return Role::Receptionist;
}

MyString Receptionist::getRoleAsSTr()
{
    return MyString("Receptionist");
}
