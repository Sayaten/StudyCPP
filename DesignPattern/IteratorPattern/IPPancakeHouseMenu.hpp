#ifndef __PANCAKE_HOUSE_MENU_HPP__
#define __PANCAKE_HOUSE_MENU_HPP__

#include "IPMenuItem.hpp"
#include "IPMenuIterator.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PancakeHouseMenu
{
	public:
		PancakeHouseMenu();
		void addItem(string name, string description, bool vegetarian, double price);
		class PancakeHouseMenuIterator : public MenuIterator
		{
			public:
				PancakeHouseMenuIterator(vector<MenuItem> &items);
				virtual MenuItem& next() override { return items[position++]; }
				virtual bool hasNext() override { return position < items.size(); }
			private:
				vector<MenuItem> &items;
				int position;
		};
		PancakeHouseMenuIterator* createIterator();
	private:
		vector<MenuItem> menuItems;
};

#endif
