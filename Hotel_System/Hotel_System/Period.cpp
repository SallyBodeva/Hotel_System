#include "Period.h"
#include <fstream>

bool operator==(const Period& lhs, const Period& rhs)
{
	if (lhs.getStartdate() == rhs.getStartdate() && lhs.getEndDate() == rhs.getEndDate())
	{
		return true;
	}
	return false;
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

int Period::getNightsCount()
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

bool Date::operator<(const Date& other) const
{
	if (year != other.year)
	{
		return year < other.year;
	}
	if (month != other.month)
	{
		return month < other.month;
	}
	return day < other.day;
}

bool Date::operator==(const Date& other) const
{
	if (year == other.year && this->month == other.month && this->day == other.day)
	{
		return true;
	}
	return false;
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
