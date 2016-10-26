#include "CPStereo.hpp"
#include <iostream>
#include <string>

using namespace std;

Stereo::Stereo(string place)
{
	vol = 0;
	this -> place = place;
}

void Stereo::on()
{
	cout << place << " Stereo On" << endl;
}

void Stereo::off()
{
	cout << place << " Stereo Off" << endl;
}

void Stereo::setCD()
{
	cout << place << " Stereo Set CD" << endl;
}

void Stereo::removeCD()
{
	cout << place << " Stereo Remove CD" << endl;
}

void Stereo::setVolume(float vol)
{
	this -> vol = vol;
	cout << place << " Stereo Set Volume " << vol << endl;
}

string Stereo::toString()
{
	return place;
}
