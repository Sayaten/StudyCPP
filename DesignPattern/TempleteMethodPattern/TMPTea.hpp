#ifndef __TEA_HPP__
#define __TEA_HPP__

#include "TMPCaffeinBeverage.hpp"
#include <iostream>

using namespace std;

class Tea : public CaffeinBeverage
{
	public:
		virtual void brew()
		{
			cout << "Steep tea bag" << endl;
		}
		virtual void addCondiments()
		{
			cout << "Add lemon" << endl;
		}
};

#endif
