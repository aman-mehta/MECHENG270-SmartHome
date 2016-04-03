#include "StatusManager.h"

StatusManager::StatusManager(DeviceModel* device)
{
	//initialise members
	deviceModel = device;
	statusUI = new StatusUI();
}

StatusManager::~StatusManager()
{
	//destroy UI object
	delete statusUI;
}

void StatusManager::InvokeUserInteraction()
{
	//create string to be displayed in the UI
	string message = CreateString();
	
	//display the device status and waits for user input to continue
	statusUI->GetUserCommand(message);	
}

//create the string to be displayed by the UI
string StatusManager::CreateString()
{
	//initialise variables
	stringstream message,command;
	string online = "offline";
	string power = "off";
	string com = "cannot";
	string text = "is not";
	string safe = "is not";
	int iD = deviceModel->GetId();

	//check power status and adjust power string
	if (deviceModel->GetPowerStatus()){
		power= "on";
	}
	
	//check online status and adjust online string
	if (deviceModel->GetOnlineStatus()){
		online="on";
	}
	
	//check if device is device enabled and adjust com string
	if (deviceModel->GetCommandEnabled()){
		com = "can";
		//assign max command
		command<<" [0-"<<deviceModel->GetMaxCommand()<<"]";
	}
	
	//check if device is text enabled and adjust text string
	if(deviceModel->GetTextEnabled()){
		text = "is";
	}
	
	//check if device is safety related and adjust safe string
	if(deviceModel->GetSafetyRelated()){
		safe = "is";
	}
	
	//contruct message to be sent to UI
	message<<"The device (ID#"<<iD<<") is currently powered "<<power<<" and is "<<online<<"\n";
	message<<"The device "<<safe<<" safety related\n";
	message<<"The device "<<text<<" text capable"; 
	//if device is text enabled, get text status
	if(deviceModel->GetTextEnabled()){
		string tStat= deviceModel->GetTextStatus();
		message<<". Current status : " <<tStat;
	}
	message<<"\nThe device "<<com<< " execute commands"<<command.str()<<"\n";
	
	return message.str();
}
