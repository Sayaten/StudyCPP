#ifndef __CP_LIGHT_OFF_COMMAND_HPP__
#define __CP_LIGHT_OFF_COMMAND_HPP__

#include "CPLight.hpp"
#include "CPCommand.hpp"
#include <string>

using namespace std;

class LightOffCommand : public Command
{
	public:
		LightOffCommand(Light &light);
		virtual void execute() { light.off(); }
		virtual string toString() { return light.toString() + " light turn off command"; } 
	private:
		Light &light;
};

#endif
