#pragma once
#include "MyString.h"

enum class Classification
{
	Regular,
	Gold,
	Platinum
};

class Guest {

private:
	MyString clientNumber;
	MyString firtsName;
	MyString lastName;
	MyString phoneNumber;
	MyString email;
	Classification classifiication;
};