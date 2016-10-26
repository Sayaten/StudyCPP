#include "CPSimpleRemoteControl.hpp"
#include "CPLightOnCommand.hpp"
#include "CPGarageDoorOpenCommand.hpp"

int main()
{
	SimpleRemoteControl remote;
	Light light;
	LightOnCommand lightOn(light);
	GarageDoor door;
	GarageDoorOpenCommand doorOpen(door);

	remote.setCommand(lightOn);
	remote.buttonWasPressed();
	remote.setCommand(doorOpen);
	remote.buttonWasPressed();

	return 0;
}
