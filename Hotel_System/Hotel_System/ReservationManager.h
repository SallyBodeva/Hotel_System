#pragma once
#include "MyVector.hpp"
#include "Reservation.h"
#include "Room.h"
#include "Guest.h";
#include "Period.h"


class ReservationManager {
public:

	Reservation createReservation(const Guest& guest, const MyVector<Guest>& guests,  Room* room, const Period& period);
	bool deleteReservation(int id);

private:
	MyVector<Reservation> reservations;
};