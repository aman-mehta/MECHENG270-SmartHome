#include "PowerManager.h"


PowerManager::PowerManager(DeviceModel* device)
{
	//initialize members
	deviceModel= device;
	powerUI= new PowerUI();
}

PowerManager::~PowerManager()
{
	//dispose of all members
	delete powerUI;
}

void PowerManager::InvokeUserInteraction()
{	
	//get current power status of the selected device
	bool powerStatus= deviceModel->GetPowerStatus();
	
	//display power options and get input from user
	int command = powerUI->GetUserCommand(powerStatus);
	
	if (!(command==0 || command==1)) {
		
		//if user input is invalid display an error
		powerUI->PrintError();
	
	} else {
		//check if user wants to change the power status
		if (command == 1) {
			
			if (powerStatus == 1) {
				//if power status is on turn it off
				int powerSetting = 0;
				deviceModel->SetPower(powerSetting);
				
			} else if (powerStatus == 0) {
				//if power status if off turn it on
				int powerSetting = 1;
				deviceModel->SetPower(powerSetting);
				
			}
		
		}
	}
}
