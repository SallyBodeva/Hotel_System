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

class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;
    virtual double calculatePrice(double initialPrice) const = 0;
};

class BasicPricing : public PricingStrategy {

    double calculatePrice(double initialPrice) const override;
};

class DemandPricing : public PricingStrategy {

    double calculatePrice(double initialPrice) const override;
};

class SeasonPricing : public PricingStrategy {

    double calculatePrice(double initialPrice) const override;
};

class WeekendPricing : public PricingStrategy {

    double calculatePrice(double initialPrice) const override;
};