#ifndef __FP_PIZZA_HPP__
#define __FP_PIZZA_HPP__

#include <string>
#include <list>
#include <iostream>

using namespace std;

class Pizza
{
	public:
		void prepare();
		void bake();
		virtual void cut()
		{
			cout << "Cutting the pizza into diagonal slices" << endl;
		}
		void box();
		string getName();
	protected:
		string name;
		string dough;
		string sauce;
		list<string> toppings;
};

#endif
