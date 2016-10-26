#ifndef __DP_PIZZA_STORE_HPP__
#define __DP_PIZZA_STORE_HPP__

#include <string>
#include "FPPizza.hpp"

using namespace std;

class PizzaStore 
{
	public:
		Pizza* orderPizza(const string& type); 
		virtual Pizza* createPizza(const string& type) = 0;
	private:
};

#endif
