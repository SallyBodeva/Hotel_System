#include "IncomeManager.h"

IncomeManager::IncomeManager(const ReservationManager& resManager)
{
}

double IncomeManager::getIncomeForDay(const Date& date) const
{
    const MyVector<Reservation>& reservations = this->reservationManager.getAllReservations();
    int count = reservations.getSize();

    double income = 0;

    for (size_t i = 0; i < count; i++)
    {
        if (reservations[i].getPeriod().includes(date))
        {
            income += reservations[i].getBill();
        }
    }
    return income;
}

double IncomeManager::getIncomeForMonth(int month, int year) const
{
    return 0.0;
}

double IncomeManager::getIncomeForYear(int year) const
{
    return 0.0;
}

double IncomeManager::getIncomeByRoomType(Room* room) const
{
    return 0.0;
}

void IncomeManager::exportReportToFile(const MyString& fileName) const
{
}
