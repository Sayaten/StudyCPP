#include "CPSimpleRemoteControl.hpp"

SimpleRemoteControl::SimpleRemoteControl()
{
	slot = nullptr;
}

void SimpleRemoteControl::setCommand(Command &command)
{
	this -> slot = &command;
}

void SimpleRemoteControl::buttonWasPressed()
{
	if(slot != nullptr)
		slot -> execute();
}
