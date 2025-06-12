#pragma once
#include "ReservationManager.h"
#include "Room.h"
#include "MyString.h"
#include "Period.h"


class IncomeManager {
public:
    IncomeManager(const ReservationManager& resManager);

    double getIncomeForDay(const Date& date) const;
    double getIncomeForMonth(int month, int year) const;
    double getIncomeForYear(int year) const;
    double getIncomeByRoomType(Room* room) const;

    void exportReportToFile(const MyString& fileName) const;

private:
    const ReservationManager& reservationManager;

};