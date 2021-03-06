#ifndef __CP_GARAGE_DOOR_OPEN_COMMAND_HPP__
#define __CP_GARAGE_DOOR_OPEN_COMMAND_HPP__

#include "CPCommand.hpp"
#include "CPGarageDoor.hpp"

class GarageDoorOpenCommand : public Command
{
	public:
		GarageDoorOpenCommand(GarageDoor &door);
		virtual void execute() { door.open(); }
		virtual string toString() { return door.toString() + " door open command"; }
	private:
		GarageDoor &door;
};

#endif
