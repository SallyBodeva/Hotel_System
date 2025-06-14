#include "PricingStrategyFactory.h"
#include "Constants.h"

PricingStrategy* PricingStrategyFactory::createStrategyByType(const MyString& type)
{
    if (type == DEMAND_PRICING) {
        return new DemandPricing();
    }
    else if (type == SEASON_PRICING) {
        return new SeasonPricing();
    }
    else if (type == WEEKEND_PRICING) {
        return new WeekendPricing();
    }
    else if (type == BASIC_PRICING) {
        return new BasicPricing();
    }
    else {
        std::cerr << "Unknown room type: " << type << '\n';
        return nullptr;
    }
}
