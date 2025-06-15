#pragma once
#include "MyString.h"

struct Date
{
    int year;
    int month;
    int day;

    Date() = default;
    Date(int day, int month, int year);

    int getDaysInMonth() const;

   const MyString getDate() const;
};

bool operator<(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);

class Period {
public:

    Period() = default;
    Period(int startDay,int startMonth, int startYear,int endDay, int endMonth, int endYear);
    MyString getPeriod();
    const Date getStartdate() const;
    const Date getEndDate() const ;

    bool serialize(std::ofstream& out) const;
    bool deserialize(std::ifstream& in);

    int getNightsCount() const;
    bool includes(Date partivularDate) const;

    int getDaysInMonth(int month, int year)const;
    int getDaysInYear(int year)const;

private:

    Date startDate;
    Date endDate;
};


bool operator==(const Period& lhs, const Period& rhs);