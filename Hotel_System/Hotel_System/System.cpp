#include "System.h"
#include <sstream>

void System::run()
{
    try
    {
        this->userManager.seeder();

        displayMenu();

        while (true)
        {
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

    if (command == "1") {
        cmd = new LogIn();
    }
   /* else if (command == "addroom") {
        cmd = new CreateRoom();
    }
    else if (command == "registerguest") {
        cmd = new RegisterGuest();
    }
    else if (command == "createreservation") {
        cmd = new CreateReservation();
    }
    else if (command == "viewavailablerooms") {
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
        cmd->execute(*this,arguments); 
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


void System::displayMenu() const
{
    std::cout << "--- HOTEL MANAGEMENT SYSTEM MENU ---" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    if (!isLoggedIn) 
    { 
        std::cout << "1. Log In" << std::endl;
        std::cout << "0. Exit System" << std::endl;
    }

    else 
    { 
        std::cout << "Logged in as: " << currentUser->getUsername() << " (" << currentUser->getRoleAsSTr() << ")" << std::endl;

        std::cout << "------------------------------------" << std::endl;

        if (currentUser->getRole() == Role::Manager) {
            std::cout << "2. Register new Employee" << std::endl;
            std::cout << "3. Add Room" << std::endl;
            std::cout << "4. View Available Rooms" << std::endl;
            std::cout << "5. View Current Reservations" << std::endl;
            std::cout << "------------------------------------" << std::endl;
            std::cout << "6. Log Out" << std::endl;
        }

        if (currentUser->getRole() == Role::Receptionist) {
            std::cout << "2. Register guest" << std::endl;
            std::cout << "3. Make new reservation" << std::endl;
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
