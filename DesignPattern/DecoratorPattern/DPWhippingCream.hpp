#ifndef __DP_WHIPPING_CREAM_HPP__
#define __DP_WHIPPING_CREAM_HPP__

#include "DPCondimentDecorator.hpp"
#include "DPBeverage.hpp"
#include <string>

using namespace std;

class WhippingCream : public CondimentDecorator
{
	public: 
		WhippingCream(Beverage &beverage);
		virtual string getDescription() override
		{
			return beverage.getDescription() + ", Whipping Cream";
		}
		double cost() 
		{
			return 0.1 + beverage.cost();
		}
	protected:
		Beverage &beverage;
};

#endif
