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


//class RegisterGuest : public Command {
//public:
//
//	RegisterGuest() = default;
//	void execute(System& system, const MyVector<MyString>& args) const override;
//};
//
//class CreateReservation : public Command {
//public:
//
//	CreateReservation() = default;
//	void execute(System& system, const MyVector<MyString>& args) const override;
//};
//
//class ViewAvailableRooms : public Command {
//public:
//
//	ViewAvailableRooms() = default;
//	void execute(System& system, const MyVector<MyString>& args) const override;
//};
//
//class ViewCurrentResevations : public Command {
//public:
//	ViewCurrentResevations() = default;
//	void execute(System& system, const MyVector<MyString>& args) const override;
//};
//
//class DeleteReservation : public Command {
//public:
//
//	DeleteReservation() = default;
//	void execute(System& system, const MyVector<MyString>& args) const override;
//};
//
//class CalculateIncome : public Command {
//public:
//	CalculateIncome() = default;
//	void execute(System& system, const MyVector<MyString>& args) const override;
//};
