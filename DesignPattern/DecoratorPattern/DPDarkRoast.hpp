#ifndef __DP_DARK_ROAST_HPP__
#define __DP_DARK_ROAST_HPP__

#include "DPBeverage.hpp"

class DarkRoast : public Beverage
{
	public:
		DarkRoast();
		virtual double cost() override { return 0.99; }
};

#endif
