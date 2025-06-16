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



#include "PricingStrategy.h"

double DemandPricing::calculatePrice(double initialPrice) const
{
	return initialPrice * 1.20;
}

double SeasonPricing::calculatePrice(double initialPrice) const
{
	return initialPrice * 0.90;
}

double WeekendPricing::calculatePrice(double initialPrice) const
{
	return initialPrice + 15.0;
}

double BasicPricing::calculatePrice(double initialPrice) const
{
	return initialPrice * 1;
}
