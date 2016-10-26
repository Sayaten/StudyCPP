#ifndef __FP_CHEESE_PIZZA_HPP__
#define __FP_CHEESE_PIZZA_HPP__

#include "FPPizzaIngredientFactory.hpp"
#include <iostream>

using namespace std;

class CheesePizza : public Pizza
{
	public:
		CheesePizza(PizzaIngredientFactory &ingredientFactory);
		virtual void prepare() override
		{
			cout << "Preparing " << name << endl;
		}
		dough  = new ingredientFactory.createDough();
		sauce  = new ingredientFactory.createSauce();
		cheese = new ingredientFactory.createCheese();

	private:
		PizzaIngredientFactory &ingredientFactory;
};

#endif
