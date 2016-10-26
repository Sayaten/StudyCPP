#ifndef __CP_REMOTE_CONTROL_HPP__
#define __CP_REMOTE_CONTROL_HPP__

#include "CPCommand.hpp"
#include "CPNoCommand.hpp"
#include <vector>
#include <string>

using namespace std;

class RemoteControl
{
	public:
		RemoteControl();
		void setCommand(int slot, Command &onCommand, Command &offCommand);
		void onButtonWasPushed(int slot);
		void offButtonWasPushed(int slot);
		string toString();
	private:
		vector<Command*> onCommands;
		vector<Command*> offCommands;
		string buf;
};

#endif
