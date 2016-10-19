#ifndef __DP_SOYBEAN_MILK_HPP__
#define __DP_SOYBEAN_MILK_HPP__

#include "DPCondimentDecorator.hpp"
#include "DPBeverage.hpp"
#include <string>

using namespace std;

class SoybeanMilk : public CondimentDecorator
{
	public: 
		SoybeanMilk(Beverage &beverage);
		virtual string getDescription() override
		{
			return beverage.getDescription() + ", Soybean Milk";
		}
		double cost() 
		{
			return 0.15 + beverage.cost();
		}
	protected:
		Beverage &beverage;

};

#endif
