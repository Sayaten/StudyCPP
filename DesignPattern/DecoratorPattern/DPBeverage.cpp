#include "DPBeverage.hpp"
#include <string>

using namespace std;

Beverage::Beverage()
{
	description = "No Title";
}

void Beverage::addDescription(string addStr)
{
	description += addStr;
}
