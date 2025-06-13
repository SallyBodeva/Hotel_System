#include "System.h"
#include <sstream>

void System::run()
{
    displayMenu();
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
            std::cout << "2. Add Room" << std::endl;
            std::cout << "3. View Available Rooms" << std::endl;
            std::cout << "4. View Current Reservations" << std::endl;
            std::cout << "------------------------------------" << std::endl;
            std::cout << "5. Log Out" << std::endl;
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
