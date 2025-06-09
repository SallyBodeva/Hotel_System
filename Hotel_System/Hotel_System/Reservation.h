#pragma once
#include "Room.h"
#include "Guest.h";
#include "Period.h"


class Reservation {
public:



private:
	Guest mainGuest;
	MyVector<Guest> otherGuests; // ��������� ���� �� �������� ���� � ���� �� ������
	Room* room; // ��������� ����� �� ���������� (������ ����)
	Period period; 
};