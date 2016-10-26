#ifndef __CP_GARAGE_DOOR_HPP__
#define __CP_GARAGE_DOOR_HPP__

#include <string>

using namespace std;

class GarageDoor
{
	public:
		GarageDoor(string place);
		void open();
		void close();
		string toString();
	private:
		string place;
};

#endif
