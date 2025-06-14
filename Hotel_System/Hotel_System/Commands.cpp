#include "Commands.h"
#include "Constants.h"
#include "System.h"

void LogIn::execute(System& system, const MyVector<MyString>& args) const
{
	try
	{
		MyString userName = args[0];
		MyString password = args[1];

		User* user = system.getUserManager().getUserByUserName(userName);

		if (user!= nullptr && user->getPassword() == password)
		{
			system.setCurrentUser(user);
			std::cout << "Login succssfull!\n";
		}
		else
		{
			std::cout << "Invalid username or password, please try again!\n";
		}

	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Invalid info, please try again!\n";
	}
}

void RegisterEmployee::execute(System& system, const MyVector<MyString>& args) const
{
	try
	{
		MyString userName = args[0];
		MyString password = args[1];
		MyString roleAsStr = args[2];

		Role r = Role::Manager;
		if (roleAsStr == RECEPTIONIST_AS_STR)
		{
			r = Role::Receptionist;
		}
		else if (roleAsStr == ACCOUNTANT_AS_STR)
		{
			r = Role::Accountant;
		}

		system.getUserManager().registerUser(userName,password,r);

		std::cout << "User registered successfully!";
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Invalid info, please try again!";
	}
}
