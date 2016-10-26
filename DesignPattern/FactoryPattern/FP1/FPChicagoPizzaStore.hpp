#ifndef __FP_CHICAGO_PIZZA_STORE_HPP__
#define __FP_CHICAGO_PIZZA_STORE_HPP__

#include "FPPizzaStore.hpp"
#include "FPChicagoStyleCheesePizza.hpp"

class ChicagoPizzaStore : public PizzaStore
{
	public:
		virtual Pizza* createPizza(const string &type)
		{
			if(!type.compare("cheese")) return new ChicagoStyleCheesePizza();
			else return nullptr;
			/*
			else if(!type.compare("veggie")) 
				return new ChicagoStyleVeggiePizza();
			else if(!type.compare("clam")) 
				return new ChicagoStyleClamPizza();
			else if(!type.compare("pepperoni")) 
				return new ChigagoStylePepperoniPizza();
			*/
		}
};

#endif
