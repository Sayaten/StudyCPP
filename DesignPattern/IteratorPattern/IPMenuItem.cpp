#include "IPMenuItem.hpp"

MenuItem::MenuItem()
{
}

MenuItem::MenuItem(string name, string description, bool vegetarian, double price)
	: name(name), description(description), vegetarian(vegetarian), price(price)
{
}

MenuItem& MenuItem::operator=(const MenuItem &rhs)
{
	name = rhs.getName();
	description = rhs.getDescription();
	vegetarian = rhs.getVegetarian();
	price = rhs.getPrice();
	return *this;
}

string MenuItem::getName() const
{
	return name;
}

string MenuItem::getDescription() const
{
	return description;
}

bool MenuItem::getVegetarian() const
{
	return vegetarian;
}

double MenuItem::getPrice() const
{
	return price;
}
