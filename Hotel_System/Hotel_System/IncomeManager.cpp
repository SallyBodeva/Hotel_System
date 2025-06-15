#include "IncomeManager.h"
#include "Constants.h"

IncomeManager::IncomeManager(const ReservationManager& resManager) : reservationManager(resManager)
{

}

double IncomeManager::getIncomeForDay(const Date& date) const
{
	const MyVector<Reservation>& reservations = this->reservationManager.getAllReservations();
	int count = this->reservationManager.getAllReservations().getSize();

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
	const MyVector<Reservation>& reservations = this->reservationManager.getAllReservations();

	int count = reservations.getSize();

	if (count == 0)
	{
		MyString result("Do not have any rooms");
		return result;
	}

	MyString result;
	double max = 0;

	double apartmentIncome = calculateIncomeByRoomType(APARTMENT_TYPE);
	double conferenceRoomIncome = calculateIncomeByRoomType(CONFERENCE_TYPE);
	double doubleRoomIncome = calculateIncomeByRoomType(DOUBLE_TYPE);
	double luxuryRoomIncome = calculateIncomeByRoomType(LUXURY_TYPE);
	double singleRoomType = calculateIncomeByRoomType(SINGLE_TYPE);

	if (apartmentIncome > max)
	{
		result = APARTMENT_TYPE;
		max = apartmentIncome;
	}
	if (conferenceRoomIncome > max)
	{
		result = CONFERENCE_TYPE;
		max = conferenceRoomIncome;
	}
	if (doubleRoomIncome > max)
	{
		result = DOUBLE_TYPE;
		max = doubleRoomIncome;
	}
	if (luxuryRoomIncome > max)
	{
		result = LUXURY_TYPE;
		max = luxuryRoomIncome;
	}
	if (singleRoomType > max)
	{
		result = SINGLE_TYPE;
		max = singleRoomType;
	}

	this->bestRoom = result;
	return result;
}

MyString IncomeManager::getBestRoomk() const
{
	return this->bestRoom;
}


MyString IncomeManager::analyseBestPeriod(int year)
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

	MyString result;

	switch (bestMonth) {
	case 1: result = "Januaru"; break;
	case 2:  result = "February"; break;
	case 3:  result = "March"; break;
	case 4:  result = "April"; break;
	case 5:  result = "May"; break;
	case 6:  result = "June"; break;
	case 7:  result = "July"; break;
	case 8:  result = "August"; break;
	case 9:  result = "September"; break;
	case 10:  result = "October";break;
	case 11:  result = "November";break;
	case 12:  result = "December";break;
	default:  result = "Invalid  month";break;
	}

	return result;
}

double IncomeManager::calculateIncomeByRoomType(const MyString& type)
{
	const MyVector<Reservation>& reservations = reservationManager.getAllReservations();

	int count = reservations.getSize();

	double result = 0;

	for (int i = 0; i < count; i++)
	{
		if (reservations[i].getRoom()->getType() == type)
		{
			result += reservations[i].getBill();
		}
	}

	return result;
}


void IncomeManager::exportReportToFile(const MyString& fileName) const
{

}


