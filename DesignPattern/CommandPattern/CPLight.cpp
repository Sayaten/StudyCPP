#include "CPLight.hpp"
#include <iostream>
#include <string>

using namespace std;

Light::Light(string place)
{
	this -> place = place;
}

void Light::on()
{
	cout << place << " Light On" << endl;
}

void Light::off()
{
	cout << place << " Light Off" << endl;
}

string Light::toString()
{
	return place;
}
