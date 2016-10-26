#ifndef __FP_CHICAGO_STYPE_CHEESE_PIZZA_HPP__
#define __FP_CHICAGO_STYPE_CHEESE_PIZZA_HPP__

#include "FPPizza.hpp"

class ChicagoStyleCheesePizza : public Pizza
{
	public:
		ChicagoStyleCheesePizza();
		virtual void cut() 
		{
			cout << "Cutting the pizza into square slices" << endl;
		}
};

#endif
