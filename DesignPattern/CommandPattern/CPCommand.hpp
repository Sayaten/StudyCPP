#ifndef __CP_COMMAND_HPP__
#define __CP_COMMAND_HPP__

#include <string>

using namespace std;

class Command
{
	public:
		virtual void execute() = 0;
		virtual string toString() = 0;
	protected:
		string str;
};

#endif
