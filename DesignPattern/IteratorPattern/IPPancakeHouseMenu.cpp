#include "IPPancakeHouseMenu.hpp"

PancakeHouseMenu::PancakeHouseMenu()
{
	addItem("K&B pancake combo", 
			"Pancake with scrambled egg and toast",
			true, 2.99);
	addItem("Regular pancake combo", 
			"Pancake with fried egg and sausage",
			false, 2.99);
	addItem("Blueberry pancake", 
			"Pancake made with fresh blueberry and blueberry syrup",
			true, 3.49);
	addItem("Waffle", 
			"Waffle, you can add blueberry or strawberry according to your favor", 
			false, 3.49);
}

void PancakeHouseMenu::addItem(string name, string description, bool vegetarian, double price)
{
	MenuItem item(name, description, vegetarian, price);
	menuItems.push_back(item);
}

PancakeHouseMenu::PancakeHouseMenuIterator* PancakeHouseMenu::createIterator()
{
	return new PancakeHouseMenu::PancakeHouseMenuIterator(menuItems);
}

PancakeHouseMenu::PancakeHouseMenuIterator::PancakeHouseMenuIterator(vector<MenuItem> &items)
	: items(items)
{
	position = 0;
}
