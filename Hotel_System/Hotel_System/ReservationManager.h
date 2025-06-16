#pragma once
#include "MyVector.hpp"
#include "Reservation.h"
#include "Room.h"
#include "Guest.h"
#include "Period.h"
#include "RoomManager.h"
#include "GuestManager.h"


class ReservationManager {
public:

	ReservationManager() = default;
	Reservation createReservation(const Guest& guest,  Room* room, const Period& period);
	bool deleteReservation(int id);


	void addAdditionalGuests(int reservationNumber,const Guest& guest);

	MyString getCurrentReservations();

	const MyVector<Reservation>& getAllReservations() const;

	//Reservation readFromFile(std::ifstream& file);


private:
	MyVector<Reservation> reservations;
};