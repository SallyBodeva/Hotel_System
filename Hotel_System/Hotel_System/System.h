#pragma once

#include "Accountant.h"
#include "Constants.h"
#include "Commands.h"
#include "GuestManager.h"
#include "IncomeManager.h"
#include "Manager.h"
#include "MyVector.hpp"
#include "RoomFactory.h"
#include "RoomManager.h"
#include "Receptionist.h"
#include "ReservationManager.h"
#include "PricingStrategyFactory.h"
#include "User.h"
#include "UserManager.h"

class System {
public:
    
    System();
    ~System() = default;

    void run(); 
    void executeCommand(const MyString& command, const MyVector<MyString>& arguments, bool isExist);

    UserManager& getUserManager();
    RoomManager& getRoomManager();
    ReservationManager& getReservationManager();
    IncomeManager& getIncomeManager();
    GuestManager& getGuestManager();

    User* getCurrentUser() const;
    void setCurrentUser(User* user);
    void logOut();

    bool isCommandAllowdForUser(const MyString& command);

    void loadData();
    void saveData();

private:

    void displayMenu() const;

    UserManager userManager;
    RoomManager roomManager;
    ReservationManager reservationManager; 
    IncomeManager incomeManager;
    GuestManager guestManager;

    User* currentUser = nullptr;

};