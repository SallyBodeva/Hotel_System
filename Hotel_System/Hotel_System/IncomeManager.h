#pragma once
#include "ReservationManager.h"
#include "Room.h"
#include "MyVector.hpp"
#include "MyString.h"
#include "Period.h"


struct IncomeByRoom
{
    IncomeByRoom() = default;
    IncomeByRoom(const MyString& roomType);
    MyString roomType;
    double income;
};

class IncomeManager {
private:

   /* Room* bestRoom;
    Period bestPeriod;*/

    ReservationManager reservationManager;
    MyVector<IncomeByRoom> incomesByRoom;

public:
    IncomeManager(const ReservationManager& resManager);

    double getIncomeForDay(const Date& date) const;
    double getIncomeForMonth(int month, int year) const;
    double getIncomeForYear(int year) const;
    
    MyString analyseBestRoom();
    int analyseBestPeriod(int year);

    void calculateIncomeByRoomType();
    const MyVector<IncomeByRoom>& getIncomeByRoomType() const;

    void exportReportToFile(const MyString& fileName) const;


};
