#ifndef __DP_STEAM_MILK_HPP__
#define __DP_STEAM_MILK_HPP__

#include "DPCondimentDecorator.hpp"
#include "DPBeverage.hpp"
#include <string>

using namespace std;

class SteamMilk : public CondimentDecorator
{
	public: 
		SteamMilk(Beverage &beverage);
		virtual string getDescription() override
		{
			return beverage.getDescription() + ", Steam Milk";
		}
		double cost() 
		{
			return 0.1 + beverage.cost();
		}
	protected:
		Beverage &beverage;

};

#endif
