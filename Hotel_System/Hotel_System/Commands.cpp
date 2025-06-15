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

		if (user != nullptr && user->getPassword() == password)
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

		system.getUserManager().registerUser(userName, password, r);

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
		MyString startDate = args[0];
		MyString endDate = args[1];

		int startDay = startDate.substr(0, 2).toInt();
		int startMonth = startDate.substr(3, 2).toInt();
		int startyear = startDate.substr(6, 4).toInt();

		int endDay = endDate.substr(0, 2).toInt();
		int endMonth = endDate.substr(3, 2).toInt();
		int endyear = endDate.substr(6, 4).toInt();

		Period period(startDay, startMonth, startyear, endDay, endMonth, endyear);

		std::cout << system.getRoomManager().getAvailableRoomsDurinPeriod(period) << std::endl;

	}
	catch (const std::exception&)
	{
		std::cout << "Invalid info, please try again!\n";
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

		std::cout << "Guest " << firstName << " " << lastName << " registered successfully!" << std::endl;

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
		int mainGuestId = args[0].toInt();
		int roomNumber = args[1].toInt();
		MyString startDate = args[2];
		MyString endDate = args[3];

		int startDay = startDate.substr(0, 2).toInt();
		int startMonth = startDate.substr(3, 2).toInt();
		int startyear = startDate.substr(6, 4).toInt();

		int endDay = endDate.substr(0, 2).toInt();
		int endMonth = endDate.substr(3, 2).toInt();
		int endyear = endDate.substr(6, 4).toInt();


		Guest g = system.getGuestManager().getGuestByClientNumber(mainGuestId);
		Room* r = system.getRoomManager().getRoomByNumber(roomNumber);
		Period period(startDay, startMonth, startyear, endDay, endMonth, endyear);

		system.getReservationManager().createReservation(g, r, period);

		std::cout << "Successfullt created reservation!\n";
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what();
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Invalid info, please try again!\n";
	}
}

void CancelReservation::execute(System& system, const MyVector<MyString>& args) const
{
	try
	{
		int reservationId = args[0].toInt();

		system.getReservationManager().deleteReservation(reservationId);

		std::cout << "Reservation is deleted!\n";
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what();
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Invalid info, please try again!\n";
	}
}

void AddAdditionalGuest::execute(System& system, const MyVector<MyString>& args) const
{
	try
	{
		int reservationId = args[0].toInt();

		int countGuests = args[1].toInt();

		int nextIndex = 2;

		for (int i = 0; i < countGuests; i++)
		{
			int guestId = args[nextIndex++].toInt();
			Guest g = system.getGuestManager().getGuestByClientNumber(guestId);
			system.getReservationManager().addAdditionalGuests(reservationId, g);
		}

		std::cout << "Successfully added new guests!\n";

	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what();
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Invalid info, please try again!\n";
	}
}

void ViewCurrentReservations::execute(System& system, const MyVector<MyString>& args) const
{
	try
	{
		std::cout << system.getReservationManager().getCurrentReservations() << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what();
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Invalid info, please try again!\n";
	}
}
