#pragma once

#include "Room.h"
#include "Apartment.h"
#include "ConferenceRoom.h"
#include "DoubleRoom.h"
#include "LuxuryRoom.h"
#include "SingleRoom.h"
#include "MyString.h"

class RoomFactory {
public:
    static Room* createRoomByType(const MyString& type);
};