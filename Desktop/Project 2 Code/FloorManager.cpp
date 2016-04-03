#include "FloorManager.h"

FloorManager::FloorManager(FloorModel* floor)
{
	//initialize all members
	floorModel = floor;
	floorUI = new FloorUI();
}

FloorManager::~FloorManager()
{
	//dispose all members
	delete floorUI;
}

void FloorManager::InvokeUserInteraction()
{
	//initialise variables
	int commandId, floorNumber,roomCount;
	string name, message;
	
	//get floor information and assign to variables
	roomCount = floorModel->rooms.size();
	floorNumber = floorModel->GetFloorNumber();
	name = floorModel->GetName();
	message = CreateString();

	//top level interaction is repeating loop
	while(true)
	{
		//show the floor info as a welcome message;
		floorUI->ShowFloorInfo(name,floorNumber);

		//show the menu and get user command
		commandId = floorUI->GetUserCommand(message);

		//user wants to exit this interaction		
		if((commandId < 0) || (commandId >= roomCount))
			break;
		
		//Create RoomManager and invoke InvokeUserInteraction method
		RoomManager* roomManager = new RoomManager(floorModel->rooms.at(commandId));
		roomManager->InvokeUserInteraction();
		delete roomManager;
	}
}

//Creates a string that is sent to the UI to be outputted
string FloorManager::CreateString()
{
	stringstream message;
	
	//Intialiase iterator
	vector<RoomModel*>::iterator roomIterator = floorModel->rooms.begin();
	
	//Loop through the rooms to display information on each one
	for(; roomIterator != floorModel->rooms.end(); roomIterator++)
	{
		RoomModel* roomModel = *roomIterator;
		message << roomModel->GetRoomNumber() << ") " << roomModel->GetName() << "\n";
	}
	
	//return string
	return message.str();
}
