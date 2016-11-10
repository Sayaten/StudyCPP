#include "IPWaitress.hpp"
#include "IPPancakeHouseMenu.hpp"
#include "IPDinerMenu.hpp"

int main()
{
	PancakeHouseMenu pancakeHouseMenu;
	DinerMenu dinerMenu;

	Waitress waitress(pancakeHouseMenu, dinerMenu);

	waitress.printMenu();
	
	return 0;
}
