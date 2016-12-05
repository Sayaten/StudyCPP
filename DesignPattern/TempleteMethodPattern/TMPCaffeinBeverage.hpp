#ifndef __CAFFEIN_BEVERAGE_HPP__
#define __CAFFEIN_BEVERAGE_HPP__

class CaffeinBeverage
{
	public:
		virtual void prepareRecipe() final
		{
			boilWater();
			brew();
			pourInCup();
			addCondiments();
		}
		virtual void brew() = 0;
		virtual void addCondiments() = 0;
		void boilWater();
		void pourInCup();
};


#endif
