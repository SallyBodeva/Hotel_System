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



#include "RoomFactory.h"
#include "Constants.h"
#include <iostream>

Room* RoomFactory::createRoomByType(const MyString& type)
{

    if (type == APARTMENT_TYPE) {
        return new Apartment();
    }
    else if (type == CONFERENCE_TYPE) {
        return new ConferenceRoom();
    }
    else if (type == DOUBLE_TYPE) {
        return new DoubleRoom();
    }
    else if (type == LUXURY_TYPE) {
        return new LuxuryRoom();
    }
    else if (type == SINGLE_TYPE) {
        return new SingleRoom();
    }
    else {
        return nullptr;
    }
}