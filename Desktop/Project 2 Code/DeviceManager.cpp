#include "DeviceManager.h"

DeviceManager::DeviceManager(DeviceModel* device)
{
	//initialize all members
	deviceModel =  device;
	deviceUI = new DeviceUI();
}

DeviceManager::~DeviceManager()
{
	//destroy UI object
	delete deviceUI;
}

void DeviceManager::InvokeUserInteraction()
{
	//initialise variables
	int deviceId, commandId;
	
	//get device information and assign to variables
	deviceId = deviceModel->GetId();
	string deviceName = deviceModel->GetName();
	
	//top level interaction is repeating loop
	while(true)
	{
		//show device info as a welcome message
		deviceUI->ShowDeviceInfo(deviceName, deviceId);
		
		//show the menu and get the user command
		commandId = deviceUI->GetUserCommand();
		
		//if command was out of range, break and revert to previous screen
		if ((commandId < 0) || (commandId > 2)) {
			break;
		}
		
		//check if the device is command enabled
		bool commandEnabled = deviceModel->GetCommandEnabled();
		
		//if user selected option 0, create PowerManager and invoke user interaction
		if (commandId == 0) {
			PowerManager* powerManager = new PowerManager(deviceModel);
			powerManager->InvokeUserInteraction();
			delete powerManager;
		//if user selected option 1, create StatusManager and invoke user interaction
		} else if (commandId == 1) {
			StatusManager* statusManager = new StatusManager (deviceModel);
			statusManager->InvokeUserInteraction();
			delete statusManager;
		//if user selected option 2 and the device is command enabled, create CommandManager and invoke user interaction
		} else if (commandId == 2) {
			if (commandEnabled) {
				CommandManager* commandManager = new CommandManager(deviceModel);
				commandManager->InvokeUserInteraction();
				delete commandManager;
			//if the device is not command enabled display an error message
			} else {
				deviceUI->PrintError();
			}
		}
	}	
}