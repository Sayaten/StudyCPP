#ifndef __DP_DECAF_HPP__
#define __DP_DECAF_HPP__

#include "DPBeverage.hpp"

class Decaf : public Beverage
{
	public:
		Decaf();
		virtual double cost() override { return 1.05; }
};

#endif
