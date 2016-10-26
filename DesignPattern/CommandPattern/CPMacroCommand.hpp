#ifndef __CP_MACRO_COMMAND_HPP__
#define __CP_MACRO_COMMAND_HPP__

#include "CPCommand.hpp"
#include <vector>

using namespace std;

class MacroCommand : public Command
{
	public:
		MacroCommand(Command *commands, int size);
		virtual void execute() 
		{ 
			for (auto command : commands)
				command -> execute();
		}
	private:
		vector<Command*> commands;
};

#endif
