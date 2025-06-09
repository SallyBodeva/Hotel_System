#include "Guest.h"
#include "Reservation.h"
#include "Constants.h"

Guest::Guest()
{
}

void Guest::setClasification()
{
	int reservationsCount = getAllReservationsCount();

	if (reservationsCount >= MIN_RESERVATIONS_FOR_BEIGN_GOLD)
	{
		this->classifiication = Classification::Gold;
	}
	else if (reservationsCount >= MIN_RESERVATIONS_FOR_BEIGN_PLATINUM)
	{
		this->classifiication = Classification::Platinum;
	}
	else
	{
		this->classifiication = Classification::Regular;
	}
}

void Guest::addNewReservation(Reservation* newReservation)
{
	if (newReservation != nullptr) 
	{
		previousReservations.push_back(newReservation);
		setClasification();
	}

}

int Guest::getAllReservationsCount() const
{
	return this->previousReservations.getSize();
}
