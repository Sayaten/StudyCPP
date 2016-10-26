#include "FPPizza.hpp"
#include <iostream>

using namespace std;

void Pizza::prepare()
{
	cout << "Preparing " << name << endl;
	cout << "Tossing dough..." << endl;
	cout << "Adding sauce..." << endl;
	cout << "Adding toppings: " << endl;
	for(auto topping : toppings)
		cout << topping << " " << endl;
}
void Pizza::bake()
{
	cout << "Bake for 25 minutes at 350" << endl;
}
void Pizza::box()
{
	cout << "Place pizza in official PizzaStore box" << endl;
}
string Pizza::getName()
{
	return name;
}
