#include "DPDarkRoast.hpp"
#include "DPHouseBlend.hpp"
#include "DPDecaf.hpp"
#include "DPEspresso.hpp"
#include "DPMocha.hpp"
#include "DPSteamMilk.hpp"
#include "DPSoybeanMilk.hpp"
#include "DPWhippingCream.hpp"

#include <iostream>

using namespace std;

int main()
{
	Beverage *beverage = new Espresso();
	
	cout << beverage -> getDescription() << " $" << beverage -> cost() << endl;

	Beverage *beverage2 = new DarkRoast();
	beverage2 = new Mocha(*beverage2);
	beverage2 = new Mocha(*beverage2);
	beverage2 = new WhippingCream(*beverage2);

	cout << beverage2 -> getDescription() << " $" << beverage2 -> cost() << endl;

	Beverage *beverage3 = new HouseBlend();
	beverage3 = new SoybeanMilk(*beverage3);
	beverage3 = new SteamMilk(*beverage3);
	beverage3 = new WhippingCream(*beverage3);

	cout << beverage3 -> getDescription() << " $" << beverage3 -> cost() << endl;
	return 0;
}
