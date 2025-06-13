#include "Manager.h"

Manager::Manager(const MyString& username, const MyString& password) : User(username,password)
{
}

Role Manager::getRole()
{
	return Role::Manager;
}

MyString Manager::getRoleAsSTr()
{
	return MyString("Manager");
}
