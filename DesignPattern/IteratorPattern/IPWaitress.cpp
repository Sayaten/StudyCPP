#include "IPWaitress.hpp"

Waitress::Waitress(PancakeHouseMenu &pancakeHouseMenu, DinerMenu &dinerMenu)
	: pancakeHouseMenu(pancakeHouseMenu), dinerMenu(dinerMenu)
{
}

void Waitress::printMenu()
{
	MenuIterator *pancakeIterator = pancakeHouseMenu.createIterator();
	MenuIterator *dinerIterator = dinerMenu.createIterator();

	cout << "Menu\n----\nMorning Menu" << endl;
	printMenu(pancakeIterator);
	cout << "\nLunch Menu" << endl;
	printMenu(dinerIterator);

	delete pancakeIterator;
	delete dinerIterator;
}

void Waitress::printMenu(MenuIterator *iterator)
{
	while (iterator -> hasNext())
	{
		MenuItem menuItem = iterator -> next();
		cout << menuItem.getName() << ", ";
		cout << menuItem.getPrice() << " -- ";
		cout << menuItem.getDescription() << endl;
	}
}
