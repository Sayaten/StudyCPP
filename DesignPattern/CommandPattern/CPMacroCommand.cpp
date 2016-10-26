#include "CPMacroCommand.hpp"

MacroCommand::MacroCommand(Command *command, int size)
{
	for(int i = 0 ; i < size ; ++i)
		commands.push_back(&command[i]);
}
