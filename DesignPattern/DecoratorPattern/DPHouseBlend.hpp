#ifndef __DP_HOUSEBLEND_HPP__
#define __DP_HOUSEBLEND_HPP__

#include "DPBeverage.hpp"

class HouseBlend : public Beverage
{
	public:
		HouseBlend();
		virtual double cost() override { return 0.89; }
};

#endif
