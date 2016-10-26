#include "FPPizzaStore.hpp"

Pizza* PizzaStore::orderPizza(const string& type)
{
	Pizza *pizza = createPizza(type);

	pizza -> prepare();
	pizza -> bake();
	pizza -> cut();
	pizza -> box();

	return pizza;
}
