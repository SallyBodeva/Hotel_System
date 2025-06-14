#pragma once

#include "PricingStrategy.h"
#include "MyString.h"

class PricingStrategyFactory {
public:
    static PricingStrategy* createStrategyByType(const MyString& type);
};