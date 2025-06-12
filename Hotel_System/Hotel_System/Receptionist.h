#pragma once
#include "User.h"
#include "Reservation.h"
#include "Guest.h"
#include "Period.h"

class Receptionist : public User{

public:

	Receptionist() = default;
	Receptionist(const MyString& username, const MyString& password);

	Reservation* createReservation(const Guest& mainGuest, const MyVector<Guest>& guests, const Room* const room, const Period& period);

	void addReservationToGuests(MyVector<Guest>& guests);

	void deleteReservation(MyVector<Guest>& guests);

	Role getRole() override;
};