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

const MyString Date::getDate() const
{
	MyString result;

	((((result += this->year) += "-") += this->month) += "-") += this->day;

	return result;

}
