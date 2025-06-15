#include "System.h"
#include <sstream>
#include <fstream>

System::System() : reservationManager(), incomeManager(reservationManager)
{

}

void System::run()
{
	try
	{

		this->loadData();

		std::cout << "--- HOTEL MANAGEMENT SYSTEM MENU ---" << std::endl;

		this->userManager.seeder();

		bool isExit = false;

		while (true)
		{
			if (isExit)
			{
				break;
			}

			displayMenu();

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

			executeCommand(command, args,isExit);

		}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}

}

void System::executeCommand(const MyString& command, const MyVector<MyString>& arguments, bool isExit)
{
	if (command != "log_in" && command != "exit") {
		if (!isCommandAllowdForUser(command)) {
			std::cout << "Permission denied: You are not allowed to execute this command.\n";
			return;
		}
	}

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
	else if (command == "register_guest") {
		cmd = new RegisterGuest();
	}
	else if (command == "make_new_reservation") {
		cmd = new MakeReservation();
	}
	else if (command == "cancel_reservation")
	{
		cmd = new CancelReservation();
	}
	 else if (command == "add_additional_guests_to_reservation") {
		cmd = new AddAdditionalGuest();
	}
	
	else if (command == "view_available_rooms") {
		cmd = new ViewAvailabeRooms();
	}
	else if (command == "view_current_reservations") {
		cmd = new ViewCurrentReservations();
	}
	else if (command == "calculate_income_day") {
		cmd = new CalculateIncomeDay();
	}
	else if (command == "calculate_income_month") {
		cmd = new CalculateIncomeMonth();
	}
	else if (command == "calculate_income_year") {
		cmd = new CalculateIncomeYear();
	}
	else if (command == "get_guests_loyalty") {
		cmd = new GetGuestLoyalty();
	}
	else if (command == "calculate_income_room_type") {
		cmd = new CalculateIncomeByRoomType();
	}
	else if (command == "print_report_best_room_period")
	{
		cmd = new SaveReportForBestRoomAndPeriod();
	}
	else if (command == "exit")
	{
		//cmd = new Exit();
		isExit = true;
		this->saveData();
	}

	else {
		std::cout << "Unknown command: " << command << std::endl;
		return;
	}

	if (command != "exit")
	{
		if (cmd)
		{
			cmd->execute(*this, arguments);
			delete cmd;
		}
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

bool System::isCommandAllowdForUser(const MyString& command)
{
	if (currentUser == nullptr) return false;

	Role role = currentUser->getRole();

	if (role == Role::Manager) {
		return command == "register_new_employee" ||
			command == "add_room" ||
			command == "change_pricing_strategy" ||
			command == "view_available_rooms" ||
			command == "view_current_reservations" ||
			command == "log_out" ||
			command == "exit";
	}

	if (role == Role::Receptionist) {
		return command == "register_guest" ||
			command == "make_new_reservation" ||
			command == "add_additional_guests_to_reservation" ||
			command == "cancel_reservation" ||
			command == "view_available_rooms" ||
			command == "view_current_reservations" ||
			command == "log_out" ||
			command == "exit";
	}

	if (role == Role::Accountant) {
		return command == "calculate_income_day" ||
			command == "calculate_income_month" ||
			command == "calculate_income_year" ||
			command == "calculate_income_room_type" ||
			command == "get_guests_loyalty" ||
			command == "print_report_best_room_period" ||
			command == "log_out" ||
			command == "exit";
	}

	return false;
}

void System::loadData()
{
	this->guestManager.loadGuestsFromFile();
}

void System::saveData()
{
	this->guestManager.saveGuestsToFile();
}


void System::displayMenu() const
{

	std::cout << "------------------------------------" << std::endl;

	if (this->currentUser == nullptr)
	{
		std::cout << "log_in" << std::endl;
		std::cout << "exit" << std::endl;
	}

	else
	{
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Logged in as: " << currentUser->getUsername() << " (" << currentUser->getRoleAsSTr() << ")" << std::endl;

		std::cout << "------------------------------------" << std::endl;

		if (currentUser->getRole() == Role::Manager) {
			std::cout << "register_new_employee" << std::endl; 
			std::cout << "add_room" << std::endl; 
			std::cout << "change_pricing_strategy" << std::endl; 
			std::cout << "view_available_rooms" << std::endl;
			std::cout << "view_current_reservations" << std::endl; 
			std::cout << "------------------------------------" << std::endl;
			std::cout << "log_out" << std::endl;
		}

		if (currentUser->getRole() == Role::Receptionist) {
			std::cout << "register_guest" << std::endl; 
			std::cout << "make_new_reservation" << std::endl; 
			std::cout << "add_additional_guests_to_reservation" << std::endl;
			std::cout << "view_available_rooms" << std::endl; 
			std::cout << "view_current_reservations" << std::endl; 
			std::cout << "cancel_reservation" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << "log_out" << std::endl;
		}


		if (currentUser->getRole() == Role::Accountant)
		{
			std::cout << "calculate_income_day" << std::endl; 
			std::cout << "calculate_income_month" << std::endl;
			std::cout << "calculate_income_year" << std::endl;
			std::cout << "calculate_income_room_type" << std::endl;
			std::cout << "get_guests_loyalty" << std::endl; 
			std::cout << "print_report_best_room_period" << std::endl; 
			std::cout << "------------------------------------" << std::endl;
			std::cout << "log_out" << std::endl; 
		}
		std::cout << "exit" << std::endl;
	}

	std::cout << "------------------------------------" << std::endl;
	std::cout << "Enter your choice: ";
}
