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

void LogOut::execute(System& system, const MyVector<MyString>& args) const
{
	if (system.getCurrentUser() != nullptr)
	{
		system.logOut();
		std::cout << "Logging out is successful!";
	}
}

void AddRoom::execute(System& system, const MyVector<MyString>& args) const
{
	try
	{
		MyString roomType = args[0];

		Room* room = RoomFactory::createRoomByType(roomType);


		if (room != nullptr)
		{
			system.getRoomManager().addRoom(room);
			std::cout << "Room created successfully!\n";
		}
		else
		{
			std::cout << "Invalid data, please try again!\n";
		}

	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Invalid info, please try again!\n";
	}
}

void ChangePricingStartegy::execute(System& system, const MyVector<MyString>& args) const
{
	try
	{
		MyString strategyType = args[0];
		int roomNumber = args[1].toInt();

		PricingStrategy* newStartegy = PricingStrategyFactory::createStrategyByType(strategyType);

		system.getRoomManager().getRoomByNumber(roomNumber)->setStrategy(newStartegy);
		system.getRoomManager().getRoomByNumber(roomNumber)->setCalculatedPrice();

	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Invalid info, please try again!\n";
	}
}

void ViewAvailabeRooms::execute(System& system, const MyVector<MyString>& args) const
{
	try
	{
		
	}
	catch (const std::exception&)
	{

	}
}

void RegisterGuest::execute(System& system, const MyVector<MyString>& args) const
{
	try
	{
		MyString firstName = args[0];
		MyString lastName = args[1];
		MyString phoneNumner = args[2];
		MyString emial = args[3];

		system.getGuestManager().addGuest(firstName, lastName, phoneNumner, emial);

		std::cout << "Guest " << firstName << " " << lastName << "registered successfully!" << std::endl;

	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Invalid info, please try again!\n";
	}

}

void MakeReservation::execute(System& system, const MyVector<MyString>& args) const
{
	try
	{
		int mainGuestId = args[]
		int guestsCount = 
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Invalid info, please try again!\n";
	}
}
