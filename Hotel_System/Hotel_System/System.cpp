#include "System.h"
#include <sstream>

void System::run()
{
	try
	{
		std::cout << "--- HOTEL MANAGEMENT SYSTEM MENU ---" << std::endl;

		this->userManager.seeder();


		displayMenu();

		while (true)
		{
			std::cout << "Enter: ";

			const int BUFFER_SIZE = 1024;
			char buffer[BUFFER_SIZE];

			std::cin.getline(buffer, BUFFER_SIZE);

			std::istringstream iss(buffer);

			char word[256];
			MyVector<MyString> args;

			while (iss >> word) {
				args.push_back(MyString(word));
			}

			MyString command = args[0];

			args.removeAt(0);

			executeCommand(command, args);

		}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}

}

void System::executeCommand(const MyString& command, const MyVector<MyString>& arguments)
{
	Command* cmd = nullptr;

	if (command == "log_in") {
		cmd = new LogIn();
	}
	else if (command == "register_new_employee") {
		cmd = new RegisterEmployee();
	}
	else if (command == "log_out") {
		cmd = new LogOut();
	}
	else if (command == "add_room") {
		cmd = new AddRoom();
	}
	else if (command == "change_pricing_strategy") {
		cmd = new ChangePricingStartegy();
	}
	else if (command == "change_pricing_strategy") {
		cmd = new ChangePricingStartegy();
	}
	else if (command == "register_guest") {
		cmd = new RegisterGuest();
	}
	else if (command == "make_new_reservation") {
		cmd = new RegisterGuest();
	}
	/*    else if (command == "viewavailablerooms") {
		cmd = new ViewAvailableRooms();
	}
	else if (command == "viewreservations") {
		cmd = new ViewCurrentResevations();
	}
	else if (command == "cancelreservation") {
		cmd = new DeleteReservation();
	}
	else if (command == "calculateincome") {
		cmd = new CalculateIncome();
	}
	else {
		std::cout << "Unknown command: " << command << std::endl;
		return;
	}*/

	if (cmd) {
		cmd->execute(*this, arguments);
		delete cmd;
	}
}

UserManager& System::getUserManager()
{
	return userManager;
}
RoomManager& System::getRoomManager()
{
	return roomManager;
}
ReservationManager& System::getReservationManager()
{
	return reservationManager;
}
IncomeManager& System::getIncomeManager()
{
	return incomeManager;
}
GuestManager& System::getGuestManager()
{
	return guestManager;
}
User* System::getCurrentUser() const
{
	return currentUser;
}
void System::setCurrentUser(User* user)
{
	currentUser = user;
}

void System::logOut()
{
	this->currentUser = nullptr;
}


void System::displayMenu() const
{

	std::cout << "------------------------------------" << std::endl;
	std::cout << "Please choose the desired command!" << std::endl;

	if (this->currentUser == nullptr)
	{
		std::cout << "log_in" << std::endl;// done
		std::cout << "exit_system" << std::endl;
	}

	else
	{
		std::cout << "Logged in as: " << currentUser->getUsername() << " (" << currentUser->getRoleAsSTr() << ")" << std::endl;

		std::cout << "------------------------------------" << std::endl;

		if (currentUser->getRole() == Role::Manager) {
			std::cout << "register_new_employee" << std::endl; // done
			std::cout << "add_room" << std::endl; // done
			std::cout << "change_pricing_strategy" << std::endl; // done
			std::cout << "view_available_rooms" << std::endl;
			std::cout << "view_current_reservations" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << "log_out" << std::endl;// done
		}

		if (currentUser->getRole() == Role::Receptionist) {
			std::cout << "register_guest" << std::endl; // done 
			std::cout << "make_new_reservation" << std::endl;
			std::cout << "4. View Available Rooms" << std::endl;
			std::cout << "5. View Current Reservations" << std::endl;
			std::cout << "6. Cancel reservation" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << "7. Log Out" << std::endl;
		}


		if (currentUser->getRole() == Role::Accountant)
		{
			std::cout << "2. Calculate Income" << std::endl;
			std::cout << "3. View income reports" << std::endl;
			std::cout << "4. View Client Activity and Loyalty" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << "5. Log Out" << std::endl;
		}
		std::cout << "0. Exit System (and Save Data)" << std::endl;
	}

	std::cout << "------------------------------------" << std::endl;
	std::cout << "Enter your choice: ";
}
