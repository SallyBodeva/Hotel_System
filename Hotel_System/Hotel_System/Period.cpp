#include "Period.h"
#include <fstream>

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.year != rhs.year) 
	{
		return lhs.year < rhs.year;
	}
	if (lhs.month != rhs.month) 
	{
		return lhs.month < rhs.month;
	}
	return lhs.day < rhs.day;
}

bool operator==(const Date& lhs, const Date& rhs)
{
	return lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day;
}

bool operator<=(const Date& lhs, const Date& rhs)
{
	return lhs < rhs || lhs == rhs;
}

bool operator>(const Date& lhs, const Date& rhs)
{
	return !(lhs <= rhs);
}

bool operator==(const Period& lhs, const Period& rhs)
{
	if (lhs.getStartdate() == rhs.getStartdate() && lhs.getEndDate() == rhs.getEndDate())
	{
		return true;
	}
	return false;
}

Period::Period(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear)
{
	Date startDate(startDay, startMonth, startYear);
	Date endDate(endDay, endMonth, endYear);

	this->startDate = startDate;
	this->endDate = endDate;
}

MyString Period::getPeriod()
{
	MyString result;
	result += this->getStartdate().getDate();
	result += "/";
	result += this->getEndDate().getDate();

	return result;
}

const Date Period::getStartdate() const
{
	return this->startDate;
}

const Date Period::getEndDate() const
{
	return this->endDate;
}

bool Period::serialize(std::ofstream& out) const
{
	out.write(reinterpret_cast<const char*>(&startDate), sizeof(startDate));
	out.write(reinterpret_cast<const char*>(&endDate), sizeof(endDate));
	return out.good();
}

bool Period::deserialize(std::ifstream& in)
{
	in.read(reinterpret_cast<char*>(&startDate), sizeof(startDate));
	in.read(reinterpret_cast<char*>(&endDate), sizeof(endDate));
	return in.good();
}

int Period::getNightsCount() const
{
	int nights = 0;
	Date current = startDate;

	while (current < endDate) 
	{
		nights++;
		current.day++;

		if (current.day > current.getDaysInMonth())
		{
			current.day = 1;
			current.month++;
			if (current.month > 12) {
				current.month = 1;
				current.year++;
			}
		}
	}
	return nights;
}

bool Period::includes(Date partivularDate) const
{
	if (partivularDate.day >= startDate.day && partivularDate.day <= endDate.day)
	{
		if (partivularDate.month >= startDate.month && partivularDate.month <= endDate.month)
		{
			if (partivularDate.year == startDate.year)
			{
				return true;
			}
		}
	}

	return false;
}

int Period::getDaysInMonth(int month, int year) const
{
	int days = 0;
	Date currentdate = startDate;

	while (currentdate < endDate)
	{
		if (currentdate.month == month && currentdate.year == year)
		{
			days++;
			break;
		}
		currentdate.day++;

		if (currentdate.day > currentdate.getDaysInMonth())
		{
			currentdate.day = 1;
			currentdate.month++;

			if (currentdate.month > 12) {
				currentdate.month = 1;
				currentdate.year++;
			}
		}
	}
	return days;
}

int Period::getDaysInYear(int year) const
{
	int days = 0;
	Date currentdate = startDate;

	while (currentdate < endDate)
	{
		if (currentdate.year == year)
		{
			days++;
			break;
		}
		currentdate.day++;

		if (currentdate.day > currentdate.getDaysInMonth())
		{
			currentdate.day = 1;
			currentdate.month++;

			if (currentdate.month > 12) {
				currentdate.month = 1;
				currentdate.year++;
			}
		}
	}
	return days;
}


Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::getDaysInMonth() const
{
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11: 
		return 30;
	case 2: 
		return 28;
	default: return 0; 
	}
}

const MyString Date::getDate() const
{
	MyString result;

	((((result += this->year) += "-") += this->month) += "-") += this->day;

	return result;

}
