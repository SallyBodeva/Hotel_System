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
