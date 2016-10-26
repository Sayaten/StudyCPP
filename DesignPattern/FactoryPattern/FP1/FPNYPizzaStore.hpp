#ifndef __FP_NYPIZZA_STORE_HPP__
#define __FP_NYPIZZA_STORE_HPP__

#include "FPPizzaStore.hpp"
#include "FPNYStyleCheesePizza.hpp"

class NYPizzaStore : public PizzaStore
{
	public:
		virtual Pizza* createPizza(const string &type)
		{
			if(!type.compare("cheese")) return new NYStyleCheesePizza();
			else return nullptr;
			/*
			else if(!type.compare("veggie")) 
				return new NYStyleVeggiePizza();
			else if(!type.compare("clam")) 
				return new NYStyleClamPizza();
			else if(!type.compare("pepperoni")) 
				return new NYStylePepperoniPizza();
			*/
		}
};

#endif
