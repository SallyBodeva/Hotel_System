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
        std::cerr << "Unknown room type: " << type << '\n';
        return nullptr;
    }
}