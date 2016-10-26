#ifndef __CP_SIMPLE_REMOTE_CONTROL_HPP__
#define __CP_SIMPLE_REMOTE_CONTROL_HPP__

#include "CPCommand.hpp"

class SimpleRemoteControl
{
	public:
		SimpleRemoteControl();
		void setCommand(Command &command);
		void buttonWasPressed();
	private:
		Command *slot;
};

#endif
