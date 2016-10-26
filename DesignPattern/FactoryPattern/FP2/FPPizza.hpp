#ifndef __FP_PIZZA_HPP__
#define __FP_PIZZA_HPP__

#include <string>
#include <list>
#include <iostream>

using namespace std;

class Pizza
{
	public:
		virtual ~Pizza() { delete veggies; }
		virtual void prepare() = 0;
		void bake();
		virtual void cut()
		{
			cout << "Cutting the pizza into diagonal slices" << endl;
		}
		void box();
		string getName();
		void setName(string name);
		string toString();
	protected:
		string name;
		Dough *dough;
		Sauce *sauce;
		Veggies** veggies;
		Cheese *cheese;
		Pepperoni *pepperoni;
		Clams *clam;
};

#endif
