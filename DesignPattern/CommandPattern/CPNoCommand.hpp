#ifndef __CP_NO_COMMAND_HPP__
#define __CP_NO_COMMAND_HPP__

#include "CPCommand.hpp"

class NoCommand : public Command
{
	public:
		virtual void execute() { }
		virtual string toString() { return ""; }
};

#endif
