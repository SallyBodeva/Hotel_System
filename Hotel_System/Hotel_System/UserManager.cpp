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


#include "UserManager.h"
#include "User.h"
#include "Manager.h"
#include "Accountant.h"
#include "Receptionist.h"
#include "Constants.h"

void UserManager::seeder()
{
	User* manager = new Manager(MANAGER_USERNAME, GENERAL_PASSWORD);
	users.push_back(manager);
}

bool UserManager::registerUser(const MyString& username, const MyString& password, Role role)
{
	for (size_t i = 0; i < users.getSize(); ++i) 
	{
		if (users[i]->getUsername() == username)
		{
			throw std::runtime_error("User with that username already exists\n");
			return false;
		}
	}

	User* newUser = nullptr;

	switch (role)
	{
	case Role::Manager:
		newUser = new Manager(username, password);
		break;
	case Role::Accountant:
		newUser = new Accountant(username, password);
		break;
	case Role::Receptionist:
		newUser = new Receptionist(username, password);
		break;
	default:
		break;
	}
	if (newUser != nullptr)
	{
		users.push_back(newUser);
		return true;
	};
	return false;
}


User* UserManager::getUserByUserName(const MyString& username)
{
	int usersCount = this->users.getSize();

	for (int i = 0; i < usersCount; i++)
	{
		if (users[i]->getUsername() == username)
		{
			return users[i];
		}
	}
	return nullptr;
}


void UserManager::free()
{
	int usersCount = this->users.getSize();

	for (int i = 0; i < usersCount; i++)
	{
		delete users[i];
	}
}
