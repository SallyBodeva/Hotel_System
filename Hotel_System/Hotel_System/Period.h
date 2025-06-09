#pragma once
#include "MyString.h"

struct Date
{
    int year;
    int month;
    int day;

    bool operator<(const Date& other) const {
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

    bool operator==(const Date& other) const {
        if (year == other.year && this->month == other.month && this->day == other.day)
        {
            return true;
        }
        return false;
    }

   const MyString getDate() const;
};

class Period {
public:

    MyString getPeriod();
    const Date getStartdate() const;
    const Date getEndDate() const ;

    bool serialize(std::ofstream& out) const;
    bool deserialize(std::ifstream& in);

private:

    Date startDate;
    Date endDate;
};


bool operator==(const Period& lhs, const Period& rhs);