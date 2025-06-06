#pragma once
#include "MyString.h"

class Command {
public:

	Command(const MyString& name, const MyString& info, const MyString& description, int argumentsCount);
	virtual void execute() const = 0;
	virtual ~Command() = default;

private:
	const MyString name;
	const MyString info;
	const MyString description;
	int argumentsCount;
};

class LogIn : public Command{
public:

	LogIn() = default;
	void execute() const override;
};

class CreateRoom : public Command {
public:

	CreateRoom() = default;
	void execute() const override;
};

class RegisterGuest : public Command {
public:

	RegisterGuest() = default;
	void execute() const override;
};

class CreateReservation : public Command {
public:

	CreateReservation() = default;
	void execute() const override;
};

class ViewAvailableRooms : public Command {
public:

	ViewAvailableRooms() = default;
	void execute() const override;
};

class ViewCurrentResevations : public Command {
public:
	ViewCurrentResevations() = default;
	void execute() const override;
};

class DeleteReservation : public Command {
public:

	DeleteReservation() = default;
	void execute() const override;
};

class CalculateIncome : public Command {
public:
	CalculateIncome() = default;
	void execute() const override;
};
