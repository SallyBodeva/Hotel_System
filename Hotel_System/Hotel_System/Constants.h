#pragma once
#include "MyString.h"

const MyString APARTMENT_TYPE = "Apartment";
const MyString CONFERENCE_TYPE = "Conference_room";
const MyString DOUBLE_TYPE = "Double_room";
const MyString LUXURY_TYPE = "Luxury_room";
const MyString SINGLE_TYPE = "Single_room";

const MyString DEMAND_PRICING = "Demand";
const MyString SEASON_PRICING = "Season";
const MyString WEEKEND_PRICING = "Weekend";
const MyString BASIC_PRICING = "Basic";

const int MONTH_COUNT = 12;

const int MAX_ARRAY_SIZE = 1024;
//const char ROOMS_FILE_NAME[MAX_ARRAY_SIZE] = "rooms.dat";

const int MIN_RESERVATIONS_FOR_BEIGN_GOLD = 6;
const int MIN_RESERVATIONS_FOR_BEIGN_PLATINUM = 20;
const int DISCOUNT_PERCENT_FOR_GOLD = 15;
const int DISCOUNT_PERCENT_FOR_PLATINUM = 20;


const int PEOPLE_CAPACITY_APARTMENT = 4;
const int INITIAL_PRICE_APARTMENT = 120;

const int PEOPLE_CAPACITY_SINGLE_ROOM = 1;
const int INITIAL_PRICE_SINGLE_ROOM = 50;

const int PEOPLE_CAPACITY_DOUBLE_ROOM = 2;
const int INITIAL_PRICE_DOUBLE_ROOM = 70;

const int PEOPLE_CAPACITY_CONFERENCE_ROOM = 50;
const int INITIAL_PRICE_CONFERENCE_ROOM = 2000;

const int PEOPLE_CAPACITY_LUXURY_ROOM = 2;
const int INITIAL_PRICE_LUXURY_ROOM = 140;


const MyString MANAGER_USERNAME = "Admin";

const MyString MANAGER_AS_STR = "Manager";
const MyString ACCOUNTANT_AS_STR = "Accountant";
const MyString RECEPTIONIST_AS_STR = "Receptionist";


const MyString REPORT_BEST_ROOM_PERIOD_FILE = "best.txt";
const MyString GUEST_FILE = "guests.txt";
const MyString ROOM_FILE = "rooms.txt";

const MyString GENERAL_PASSWORD = "123456";