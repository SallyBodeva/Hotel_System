#include "RoomFactory.h"
#include <iostream>

Room* RoomFactory::createRoomByType(const MyString& type) {
    if (type == "Apartment") {
        return new Apartment();
    }
    else if (type == "Conference Room") {
        return new ConferenceRoom();
    }
    else if (type == "Double Room") {
        return new DoubleRoom();
    }
    else if (type == "Luxury Room") {
        return new LuxuryRoom();
    }
    else if (type == "Single Room") {
        return new SingleRoom();
    }
    else {
        std::cerr << "Unknown room type: " << type << '\n';
        return nullptr;
    }
}