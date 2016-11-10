#ifndef __DINER_MENU_HPP__
#define __DINER_MENU_HPP__

#include "IPMenuIterator.hpp"
#include "IPMenuItem.hpp"
#include <string>

using namespace std;

class DinerMenu
{
	public:
		DinerMenu();
		void addItem(string name, string description, bool vegetarian, double price);
		class DinerMenuIterator : public MenuIterator
		{
			public:
				DinerMenuIterator(MenuItem *items, int size);
				virtual MenuItem& next() override { return items[position++]; }
				virtual bool hasNext() override { return position < size; }
			private:
				MenuItem *items;
				int position;
				int size;
		};
		DinerMenuIterator* createIterator();
	private:
		static const int MAX_ITEMS = 4;
		int numberOfItems;
		MenuItem menuItems[MAX_ITEMS];
};

#endif
