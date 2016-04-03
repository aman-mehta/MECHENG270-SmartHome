#include "CommandManager.h"

CommandManager::CommandManager(DeviceModel* device)
{
	//initialise members
	deviceModel= device;
	commandUI = new CommandUI();
}

CommandManager::~CommandManager()
{
	//destroy UI object
	delete commandUI;
}

void CommandManager::InvokeUserInteraction()
{	
	//get the max valid command for the device
	int maxCommand = deviceModel->GetMaxCommand();
	
	//display options and get user command input
	int command = commandUI->GetUserCommand(maxCommand);
	
	if(command<0 || command>maxCommand)
	{
		//display an error for invalid commands
		commandUI->PrintError();
	}else{
		//execute command on device if valid
		deviceModel->ExecuteCommand(command);
	}
}
