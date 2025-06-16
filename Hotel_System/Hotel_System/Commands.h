/**
*
* Solution to course project #5
* Object-Oriented Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2024 / 2025
*
* @author Salihe Ali Bodeva
* @idnumber 9MI0600468
* @compiler VS
*
*
*/


#pragma once
#include "MyString.h"
#include "MyVector.hpp"

class System;

class Command {
public:

	Command() = default;
	virtual void execute(System& system,const MyVector<MyString>& args) const = 0;
	virtual ~Command() = default;
};


class LogIn : public Command {
public:

	LogIn() = default;

	void execute(System& system, const MyVector<MyString>& args) const override;

};


class RegisterEmployee : public Command {
public:

	RegisterEmployee() = default;

	void execute(System& system, const MyVector<MyString>& args) const override;

};

class LogOut : public Command {
public:

	LogOut() = default;

	void execute(System& system, const MyVector<MyString>& args) const override;

};


class AddRoom : public Command {
public:

	AddRoom() = default;
	void execute(System& system, const MyVector<MyString>& args) const override;
};

class ChangePricingStartegy : public Command {
public:

	ChangePricingStartegy() = default;
	void execute(System& system, const MyVector<MyString>& args) const override;
};

class ViewAvailabeRooms : public Command {
public:

	ViewAvailabeRooms() = default;
	void execute(System& system, const MyVector<MyString>& args) const override;
};


class ViewCurrentReservations : public Command {
public:

	ViewCurrentReservations() = default;
	void execute(System& system, const MyVector<MyString>& args) const override;
};

class RegisterGuest : public Command {
public:

	RegisterGuest() = default;
	void execute(System& system, const MyVector<MyString>& args) const override;
};

class MakeReservation : public Command {
public:

	MakeReservation() = default;
	void execute(System& system, const MyVector<MyString>& args) const override;
};

class CancelReservation : public Command {
public:

	CancelReservation() = default;
	void execute(System& system, const MyVector<MyString>& args) const override;
};

class AddAdditionalGuest : public Command {
public:

	AddAdditionalGuest() = default;
	void execute(System& system, const MyVector<MyString>& args) const override;
};

class CalculateIncomeDay : public Command {
public:

	CalculateIncomeDay() = default;
	void execute(System& system, const MyVector<MyString>& args) const override;
};

class CalculateIncomeMonth : public Command {
public:

	CalculateIncomeMonth() = default;
	void execute(System& system, const MyVector<MyString>& args) const override;
};

class CalculateIncomeYear : public Command {
public:

	CalculateIncomeYear() = default;
	void execute(System& system, const MyVector<MyString>& args) const override;
};

class GetGuestLoyalty : public Command {
public:

	GetGuestLoyalty() = default;
	void execute(System& system, const MyVector<MyString>& args) const override;
};

class CalculateIncomeByRoomType : public Command {
public:

	CalculateIncomeByRoomType() = default;
	void execute(System& system, const MyVector<MyString>& args) const override;
};

class SaveReportForBestRoomAndPeriod : public Command {
public:

	SaveReportForBestRoomAndPeriod() = default;
	void execute(System& system, const MyVector<MyString>& args) const override;
};

class Exit : public Command {
public:
	Exit() = default;
	void execute(System& system, const MyVector<MyString>& args) const override;
};
