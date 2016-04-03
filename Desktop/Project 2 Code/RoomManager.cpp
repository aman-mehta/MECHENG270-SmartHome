#include "RoomManager.h"

RoomManager::RoomManager(RoomModel* room)
{
	//initialize all members
	roomModel = room;
	roomUI = new RoomUI();
}

RoomManager::~RoomManager()
{
	//dispose all members
	delete roomUI;
}

void RoomManager::InvokeUserInteraction()
{
	//initialiase variables
	int commandId, roomNumber,floorNumber;
	string name, message;
	
	//get room information and assign to variables
	roomNumber = roomModel->GetRoomNumber();
	floorNumber = roomModel->GetFloorNumber();
	name= roomModel->GetName();
	message = CreateString();

	//top level interaction is repeating loop
	while(true)
	{
		//show the room info as a welcome message;
		roomUI->ShowRoomInfo(name,roomNumber,floorNumber);

		//show the menu and get user command
		commandId = roomUI->GetUserCommand(message);

		//user wants to exit this interaction		
		if(!CheckDeviceId(commandId)) {
			break;
		}
		
		//get postion of selected device in vector
		int position = GetPosition(commandId);
		
		//check if device is offline
		if (!roomModel->GetOnlineStatus(commandId)) {
			roomUI->PrintOfflineError();
		} else {
			//invoke Device Manager with commandID as deviceID
			DeviceManager* deviceManager = new DeviceManager(roomModel->devices.at(position));
			deviceManager->InvokeUserInteraction();
			delete deviceManager;
		}
	}
}

//creates a string that is sent to the UI to be outputted
string RoomManager::CreateString()
{
	stringstream message;
	
	//intialiase iterator
	vector<DeviceModel*>::iterator deviceIterator = roomModel->devices.begin();
	
	//loop through the devices to display information on each one
	for(; deviceIterator != roomModel->devices.end(); deviceIterator++)
	{
		DeviceModel* deviceModel = *deviceIterator;
		message << deviceModel->GetId() << ") " << deviceModel->GetName() << "\n";
	}
	
	//return string
	return message.str();
}

//checks if the device ID input is valid
bool RoomManager::CheckDeviceId(int Id)
{	
	//intitalise boolean to 0
	bool check = 0;
	
	//loop through all devices and check Id one by one
	for (unsigned int i=0; i < roomModel->devices.size(); i++) {
		if (roomModel->devices[i]->GetId() == Id) {
			check = 1;
		}
	}
	
	return check;
}

//checks the position of a specific device in the devices vector
int RoomManager::GetPosition(int Id)
{	
	//intialise position to -1
	int pos=-1;
	
	//loop through all devices and check Id one by one
	for (unsigned int i=0; i < roomModel->devices.size(); i++) {
		if (roomModel->devices[i]->GetId() == Id) {
			pos = i;
		}
	}
	
	return pos;
}


