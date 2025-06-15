#pragma once
#include "ReservationManager.h"
#include "Room.h"
#include "MyVector.hpp"
#include "MyString.h"
#include "Period.h"



class IncomeManager {
private:

    MyString bestRoom;

    const ReservationManager& reservationManager;

public:
    IncomeManager() = default;
    IncomeManager(const ReservationManager& resManager);

    double getIncomeForDay(const Date& date) const;
    double getIncomeForMonth(int month, int year) const;
    double getIncomeForYear(int year) const;
    
    MyString analyseBestRoom();
    MyString getBestRoomk()const;

    MyString analyseBestPeriod(int year);

    double calculateIncomeByRoomType(const MyString& type);


    void exportReportToFile(const MyString& fileName) const;


};
