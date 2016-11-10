#ifndef __WAITRESS_HPP__
#define __WAITRESS_HPP__

#include "IPPancakeHouseMenu.hpp"
#include "IPDinerMenu.hpp"
#include "IPMenuItem.hpp"
#include "IPMenuIterator.hpp"
#include <iostream>

using namespace std;

class Waitress
{
	public:
		Waitress(PancakeHouseMenu &pancakeHouseMenu, DinerMenu &dinerMenu);
		void printMenu();
	private:
		void printMenu(MenuIterator *iterator);
		PancakeHouseMenu &pancakeHouseMenu;
		DinerMenu &dinerMenu;
};

#endif
