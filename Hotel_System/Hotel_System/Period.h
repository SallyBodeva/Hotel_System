#pragma once
#include "MyString.h"

struct Date
{
    int year;
    int month;
    int day;

    bool operator<(const Date& other) const;

    bool operator==(const Date& other) const;

    int getDaysInMonth() const;

   const MyString getDate() const;
};

class Period {
public:

    MyString getPeriod();
    const Date getStartdate() const;
    const Date getEndDate() const ;

    bool serialize(std::ofstream& out) const;
    bool deserialize(std::ifstream& in);

    int getNightsCount() const;

private:

    Date startDate;
    Date endDate;
};


bool operator==(const Period& lhs, const Period& rhs);