#ifndef __MENU_ITEM_HPP__
#define __MENU_ITEM_HPP__

#include <string>

using namespace std;

class MenuItem
{
	public:
		MenuItem();
		MenuItem(string name, string description, bool vegetarian, double price);
		MenuItem& operator=(const MenuItem &rhs);
		string getName() const;
		string getDescription() const;
		bool getVegetarian() const;
		double getPrice() const;
	private:
		string name;
		string description;
		bool vegetarian;
		double price;
};

#endif
