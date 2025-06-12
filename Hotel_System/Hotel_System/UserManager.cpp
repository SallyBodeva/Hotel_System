#include "UserManager.h"
#include "User.h"
#include "Manager.h"
#include "Accountant.h"
#include "Receptionist.h"

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

void UserManager::login(const MyString& username, const MyString& password)
{
	int usersCount = users.getSize();

	User* neededUser = nullptr;

	for (int i = 0; i < usersCount; i++)
	{
		if (users[i]->getUsername() == username && users[i]->getPassword() == password)
		{
			neededUser = users[i];
		}
	}
	this->loggedUser = neededUser;
}


// Довърши историите 

const MyVector<ActionLog>& UserManager::getLogs() const
{
	// TODO: insert return statement here
}

void UserManager::printHistory()
{
}
