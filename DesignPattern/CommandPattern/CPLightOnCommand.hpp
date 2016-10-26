#ifndef __CP_LIGHT_ON_COMMAND_HPP__
#define __CP_LIGHT_ON_COMMAND_HPP__

#include "CPCommand.hpp"
#include "CPLight.hpp"
#include <string>

using namespace std;

class LightOnCommand : public Command
{
	public:
		LightOnCommand(Light &light);
		virtual void execute() { light.on(); }
		virtual string toString() { return light.toString() + " light turn on command"; }
	private:
		Light &light;
};

#endif
