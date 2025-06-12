#pragma once
#include "Reservation.h"
#include "User.h"
#include "Period.h"
#include "MyVector.hpp"

class Accountant : public User{
public:
	

    Accountant() = default;
    Accountant(const MyString& username, const MyString& password);
    double calculateIncome(const MyVector<Reservation*>& reservations, const Period& period);
    double calculateIncomeFromRoomType(const MyVector<Reservation*>& reservations, const MyString& roomType, const Period& period);
    MyString calculateBestRoomType(const MyVector<Reservation*>& reservations, const MyVector<Room*>& allRooms);
    Period inputPeriod(); // за избор от потребителя на период
    void saveReportToFile(const MyString& filename, const MyString& reportContent);
    Role getRole() override;

private:

};