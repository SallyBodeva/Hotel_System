#pragma once

#include "Accountant.h"
#include "Commands.h"
#include "GuestManager.h"
#include "IncomeManager.h"
#include "Manager.h"
#include "MyVector.hpp"
#include "RoomManager.h"
#include "Receptionist.h"
#include "ReservationManager.h"
#include "User.h"
#include "UserManager.h"

class System {
public:
    
    System() = default;
    ~System() = default;

    void run(); 
    void executeCommand(const MyString& command, const MyVector<MyString>& arguments);

    UserManager& getUserManager();
    RoomManager& getRoomManager();
    ReservationManager& getReservationManager();
    IncomeManager& getIncomeManager();
    GuestManager& getGuestManager();

    User* getCurrentUser() const;
    void setCurrentUser(User* user);


    //void loadData();
    //void saveData();

private:

    void displayMenu() const;

    UserManager userManager;
    RoomManager roomManager;
    ReservationManager reservationManager; 
    IncomeManager incomeManager;
    GuestManager guestManager;

    User* currentUser = nullptr;
    bool isLoggedIn = false;

};