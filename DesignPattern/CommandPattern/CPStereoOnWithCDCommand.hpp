#ifndef __CP_STEREO_ON_WITH_CD_COMMAND_HPP__
#define __CP_STEREO_ON_WITH_CD_COMMAND_HPP__

#include "CPStereo.hpp"
#include "CPCommand.hpp"
#include <string>

using namespace std;

class StereoOnWithCDCommand : public Command
{
	public:
		StereoOnWithCDCommand(Stereo &stereo);
		virtual void execute()
		{
			stereo.on();
			stereo.setCD();
			stereo.setVolume(11);
		}
		virtual string toString() { return stereo.toString() + " stereo turn on command"; }
	private:
		Stereo &stereo;
};

#endif
