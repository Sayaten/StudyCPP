#ifndef __FP_PIZZA_INDGREDIENT_FACTORY_HPP__
#define __FP_PIZZA_INDGREDIENT_FACTORY_HPP__

#include "FPIngredient.hpp"

class PizzaIngredientFactory
{
	public:
		virtual Dough* createDough() = 0;
		virtual Sauce* createSauce() = 0;
		virtual Cheese* createCheese() = 0;
		virtual Veggies* createVeggies() = 0;
		virtual Pepperoni* createPepperoni() = 0;
		virtual Clams* createClam() = 0;
};

#endif
