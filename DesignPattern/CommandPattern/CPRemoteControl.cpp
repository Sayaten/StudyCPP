#include "CPRemoteControl.hpp"

RemoteControl::RemoteControl()
{
	Command *noCommand = new NoCommand();
	for(int i = 0 ; i < 7 ; ++i)
	{
		onCommands.push_back(noCommand);
		offCommands.push_back(noCommand);
	}
}

void RemoteControl::setCommand(int slot, Command &onCommand, Command &offCommand)
{
	onCommands[slot] = &onCommand;
	offCommands[slot] = &offCommand;
}
void RemoteControl::onButtonWasPushed(int slot)
{
	onCommands[slot] -> execute();
}
void RemoteControl::offButtonWasPushed(int slot)
{
	offCommands[slot] -> execute();
}
string RemoteControl::toString()
{
	buf = "";
	buf = "\n----- Remote Control -----\n";
	for (int i = 0 ; i < onCommands.size() ; ++i)
		buf += "[slot " + std::to_string(i) + "] " 
			+ onCommands[i] -> toString() + ", "
			+ offCommands[i] -> toString() + "\n";
	return buf;
}

