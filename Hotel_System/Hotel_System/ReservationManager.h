#pragma once
#include "MyVector.hpp"
#include "Reservation.h"
#include "Room.h"
#include "Guest.h"
#include "Period.h"


class ReservationManager {
public:

	ReservationManager() = default;
	Reservation createReservation(const Guest& guest,  Room* room, const Period& period);
	bool deleteReservation(int id);


	void addAdditionalGuests(int reservationNumber,const Guest& guest);

	MyString getCurrentReservations();

	const MyVector<Reservation>& getAllReservations() const ;

private:
	MyVector<Reservation> reservations;
};