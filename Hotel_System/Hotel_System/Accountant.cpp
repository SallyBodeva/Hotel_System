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


#include "Accountant.h"

Accountant::Accountant(const MyString& username, const MyString& password): User(username,password)
{

}

Role Accountant::getRole()
{
    return Role::Accountant;
}

MyString Accountant::getRoleAsSTr()
{
    return MyString("Accountant");
}
