#include "IncomeManager.h"
#include "Constants.h"

IncomeManager::IncomeManager(const ReservationManager& resManager) : reservationManager(resManager)
{
    incomesByRoom.push_back(IncomeByRoom(APARTMENT_TYPE));
    incomesByRoom.push_back(IncomeByRoom(CONFERENCE_TYPE));
    incomesByRoom.push_back(IncomeByRoom(DOUBLE_TYPE));
    incomesByRoom.push_back(IncomeByRoom(LUXURY_TYPE));
    incomesByRoom.push_back(IncomeByRoom(SINGLE_TYPE));

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
            income += reservations[i].getDailyBill();
        }
    }
    return income;
}

double IncomeManager::getIncomeForMonth(int month, int year) const
{
    const MyVector<Reservation>& reservations = this->reservationManager.getAllReservations();

    int count = reservations.getSize();

    double income = 0;

    for (int i = 0; i < count; i++)
    {
         int days = reservations[i].getPeriod().getDaysInMonth(month, year);
         income += days * reservations[i].getDailyBill();
    }

    return income;
}

double IncomeManager::getIncomeForYear(int year) const
{
    const MyVector<Reservation>& reservations = this->reservationManager.getAllReservations();

    int count = reservations.getSize();

    double income = 0;

    for (int i = 0; i < count; i++)
    {
        int days = reservations[i].getPeriod().getDaysInYear(year);
        income += days * reservations[i].getDailyBill();
    }

    return income;
}

MyString IncomeManager::analyseBestRoom()
{
    MyString bestType;
    double maxIncome = 0;

    int incomesByRoomCount = this->incomesByRoom.getSize();
    for (int i = 0; i < incomesByRoomCount; i++)
    {
        if (incomesByRoom[i].income > maxIncome)
        {
            maxIncome = incomesByRoom[i].income;
            bestType = incomesByRoom[i].roomType;
        }
    }

    return bestType;
}

int IncomeManager::analyseBestPeriod(int year)
{
    double maxIncome = 0;
    int bestMonth = 1;

    for (int i = 1; i <= MONTH_COUNT; i++)
    {
        if (getIncomeForMonth(i, year) > maxIncome)
        {
            maxIncome = getIncomeForMonth(i, year);
            bestMonth = i;
        }
    }
    return bestMonth;
}


void IncomeManager::calculateIncomeByRoomType() 
{ 

    for (int i = 0; i < incomesByRoom.getSize(); ++i)
    {
        incomesByRoom[i].income = 0; 
    }

    const MyVector<Reservation>& reservations = reservationManager.getAllReservations();

    for (int i = 0; i < reservations.getSize(); ++i)
    {
        const MyString& type = reservations[i].getRoom()->getType();
        double income = reservations[i].getBill();

        for (int j = 0; j < incomesByRoom.getSize(); ++j)
        {
            if (incomesByRoom[j].roomType == type)
            {
                incomesByRoom[j].income += income;
                break;
            }
        }
    }
}

const MyVector<IncomeByRoom>& IncomeManager::getIncomeByRoomType() const
{
    return this->incomesByRoom;
}

void IncomeManager::exportReportToFile(const MyString& fileName) const
{

}

IncomeByRoom::IncomeByRoom(const MyString& roomType)
{
    this->roomType = roomType;
    this->income = 0;
}
