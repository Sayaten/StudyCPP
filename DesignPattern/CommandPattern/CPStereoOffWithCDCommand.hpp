#ifndef __CP_STEREO_OFF_WITH_CD_COMMAND_HPP__
#define __CP_STEREO_OFF_WITH_CD_COMMAND_HPP__

#include "CPStereo.hpp"
#include "CPCommand.hpp"
#include <string>

using namespace std;

class StereoOffWithCDCommand : public Command
{
	public:
		StereoOffWithCDCommand(Stereo &stereo);
		virtual void execute()
		{
			stereo.off();
			stereo.removeCD();
			stereo.setVolume(0);
		}
		virtual string toString() { return stereo.toString() + " stereo turn off command"; }
	private:
		Stereo &stereo;
};

#endif
