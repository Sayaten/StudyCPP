#ifndef __CP_LIGHT_ON_COMMAND_HPP__
#define __CP_LIGHT_ON_COMMAND_HPP__

#include "CPCommand.hpp"
#include "CPLight.hpp"

class LightOnCommand : public Command
{
	public:
		LightOnCommand(Light &light);
		virtual void execute() { light.on(); }
	private:
		Light &light;
};

#endif
