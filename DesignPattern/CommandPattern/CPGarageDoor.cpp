#include "CPGarageDoor.hpp"
#include <iostream>
#include <string>

using namespace std;

GarageDoor::GarageDoor(string place)
{
	this -> place = place;
}

void GarageDoor::open()
{
	cout << place << " Door Open" << endl;
}

void GarageDoor::close()
{
	cout << place << " Door Close" << endl;
}

string GarageDoor::toString()
{
	return place;
}
