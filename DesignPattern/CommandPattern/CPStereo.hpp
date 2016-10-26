#ifndef __CP_STEREO_HPP__
#define __CP_STEREO_HPP__

#include <string>

using namespace std;

class Stereo
{
	public:
		Stereo(string place);
		void on();
		void off();
		void setCD();
		void removeCD();
		void setVolume(float vol);
		string toString();
	private:
		float vol;
		string place;
};

#endif
