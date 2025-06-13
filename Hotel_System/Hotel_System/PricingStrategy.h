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