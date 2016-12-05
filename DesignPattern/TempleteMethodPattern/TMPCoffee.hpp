#ifndef __COFFEE_HPP
#define __COFFEE_HPP

#include "TMPCaffeinBeverage.hpp"
#include <iostream>

using namespace std;

class Coffee : public CaffeinBeverage
{
	public:
		virtual void brew()
		{
			cout << "Brew coffee grinds" << endl;
		}
		virtual void addCondiments()
		{
			cout << "Add sugar and milk" << endl;
		}
};

#endif
