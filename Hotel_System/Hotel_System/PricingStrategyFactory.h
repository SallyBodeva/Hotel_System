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

#include "PricingStrategy.h"
#include "MyString.h"

class PricingStrategyFactory {
public:
    static PricingStrategy* createStrategyByType(const MyString& type);
};