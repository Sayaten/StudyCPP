#include "CPRemoteControl.hpp"
#include "CPLightOnCommand.hpp"
#include "CPLightOffCommand.hpp"
#include "CPGarageDoorOpenCommand.hpp"
#include "CPGarageDoorCloseCommand.hpp"
#include "CPStereoOnWithCDCommand.hpp"
#include "CPStereoOffWithCDCommand.hpp"

#include "CPLight.hpp"
#include "CPGarageDoor.hpp"
#include "CPStereo.hpp"

#include <iostream>

using namespace std;

int main()
{
	RemoteControl remote;

	Light light("living room");
	GarageDoor door("kitchen");
	Stereo stereo("my room");
	
	LightOnCommand lightOn(light);
	LightOffCommand lightOff(light);

	GarageDoorOpenCommand doorOpen(door);
	GarageDoorCloseCommand doorClose(door);

	StereoOnWithCDCommand stereoOn(stereo);
	StereoOffWithCDCommand stereoOff(stereo);

	remote.setCommand(0, lightOn, lightOff);
	remote.onButtonWasPushed(0);
	remote.offButtonWasPushed(0);

	remote.setCommand(1, doorOpen, doorClose);
	remote.onButtonWasPushed(1);
	remote.offButtonWasPushed(1);

	remote.setCommand(2, stereoOn, stereoOff);
	remote.onButtonWasPushed(2);
	remote.offButtonWasPushed(2);

	cout << remote.toString() << endl;

	return 0;
}
