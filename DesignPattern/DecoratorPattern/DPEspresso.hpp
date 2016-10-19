#ifndef __DP_ESPRESSO_HPP__
#define __DP_ESPRESSO_HPP__

#include "DPBeverage.hpp"

class Espresso : public Beverage
{
	public:
		Espresso();
		virtual double cost() override { return 1.99; }
};

#endif
