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
