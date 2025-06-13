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
