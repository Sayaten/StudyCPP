#ifndef __MENU_ITERATOR_HPP__
#define __MENU_ITERATOR_HPP__

#include "IPMenuItem.hpp"

class MenuIterator
{
	public:
		virtual bool hasNext() = 0;
		virtual MenuItem& next() = 0;
};

#endif
