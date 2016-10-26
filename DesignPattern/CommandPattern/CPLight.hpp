#ifndef __CP_LIGHT_HPP__
#define __CP_LIGHT_HPP__

#include <string>

using namespace std;

class Light
{
	public:
		Light(string place);
		void on();
		void off();
		string toString();
	private:
		string place;
};

#endif
