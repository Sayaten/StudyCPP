#include "IPDinerMenu.hpp"
#include <iostream>

DinerMenu::DinerMenu()
{
	numberOfItems = 0;

	addItem("BLT for vegetarian", 
			"menu with (Phytogenic) bacon, lettuce and tomatoes on brown bread",
			true, 2.99);
	addItem("BLT", 
			"menu with bacon, lettuce and tomatoes on brown bread",
			false, 2.99);
	addItem("Today's soup",
			"Today's soup with potato salad",
			false, 3.29);
	addItem("Hot dog",
			"Hot dog with sauerkraut, some source, onion and cheese",
			false, 3.05);
}

DinerMenu::DinerMenuIterator* DinerMenu::createIterator()
{
	return new DinerMenuIterator(menuItems, numberOfItems);
}

void DinerMenu::addItem(string name, string description, bool vegetarian, double price)
{
	MenuItem menuItem(name, description, vegetarian, price);
	if(numberOfItems >= MAX_ITEMS)
		cout << "Sorry, menu list is full. You can't add item" << endl;
	else
		menuItems[numberOfItems++] = menuItem;
}

DinerMenu::DinerMenuIterator::DinerMenuIterator(MenuItem *items, int size)
{
	this -> items = items; 
	this -> size = size;	
}
