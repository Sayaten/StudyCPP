#ifndef __DP_BEVERAGE_HPP__
#define __DP_BEVERAGE_HPP__

#include <string>

using namespace std;

class Beverage
{
	public:
		Beverage();
		virtual string getDescription() { return description; }
		void addDescription(string addStr);
		virtual double cost() = 0;
	protected:
		string description;
};

#endif
