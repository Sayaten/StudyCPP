#ifndef __CP_GARAGE_DOOR_CLOSE_COMMAND_HPP__
#define __CP_GARAGE_DOOR_CLOSE_COMMAND_HPP__

#include "CPCommand.hpp"
#include "CPGarageDoor.hpp"

class GarageDoorCloseCommand : public Command
{
	public:
		GarageDoorCloseCommand(GarageDoor &door);
		virtual void execute() { door.close(); }
		virtual string toString() { return door.toString() + " door close command"; }
	private:
		GarageDoor &door;
};

#endif
