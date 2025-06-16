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