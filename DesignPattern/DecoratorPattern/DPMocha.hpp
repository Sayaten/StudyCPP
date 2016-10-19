#ifndef __DP_MOCHA_HPP__
#define __DP_MOCHA_HPP__

#include "DPCondimentDecorator.hpp"
#include "DPBeverage.hpp"
#include <string>

using namespace std;

class Mocha : public CondimentDecorator
{
	public: 
		Mocha(Beverage &beverage);
		virtual string getDescription() override
		{
			return beverage.getDescription() + ", Mocha";
		}
		double cost() 
		{
			return 0.2 + beverage.cost();
		}
	protected:
		Beverage &beverage;
};

#endif
