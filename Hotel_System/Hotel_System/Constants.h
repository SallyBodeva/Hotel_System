#pragma once
#include "MyString.h"

const MyString APARTMENT_TYPE = "Apartment";
const MyString CONFERENCE_TYPE = "Conference Room";
const MyString DOUBLE_TYPE = "Double Room";
const MyString LUXURY_TYPE = "Luxury Room";
const MyString SINGLE_TYPE = "Single Room";

const int MONTH_COUNT = 12;

const int MAX_ARRAY_SIZE = 1024;
const char ROOMS_FILE_NAME[MAX_ARRAY_SIZE] = "rooms.dat";

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



//const MyString ACCOUNTANT_USERNAME = "SallyBodeva";
//const MyString RECEPTIONIST_USERNAME = "KatrinGeorg";

const MyString GENERAL_PASSWORD = "123456";