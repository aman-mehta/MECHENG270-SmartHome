#include "BuildingManager.h"

BuildingManager::BuildingManager()
{
	//initialize all members
	buildingUI = new BuildingUI();
	buildingModel = new BuildingModel();
}

BuildingManager::~BuildingManager()
{
	//dispose all members
	delete buildingUI;
	delete buildingModel;
}

void BuildingManager::InvokeUserInteraction()
{
	int commandId;
	string address, name;
	
	//get the number of floors in the building
	int floorCount = buildingModel->floors.size();

	//vector<FloorModel> &floors = buildingModel->GetVector();
	name = buildingModel->GetName();
	address = buildingModel->GetStreetAddress();	
	string message = CreateString();
	//top level interaction is reapting loop
	while(true)
	{	
		//show the building info as a welcome message;
		buildingUI->ShowBuildingInfo(name,address);

		//show the menu and get user command
		commandId = buildingUI->GetUserCommand(message);

		//user wants to exit this interaction		
		if((commandId < 0) || (commandId >= floorCount)) {

			break;
		}

		//invoke floor manager with commandId as floor number
		FloorManager* floorManager = new FloorManager(buildingModel->floors.at(commandId));

		floorManager->InvokeUserInteraction();

		delete floorManager;
	}
}

//Creates a string that is sent to the UI to be outputted
string BuildingManager::CreateString()
{
	stringstream message;
	
	//Intialiase iterator
	vector<FloorModel*>::iterator floorIterator = buildingModel->floors.begin();
	
	//Iterate through the floors to display information on each one
	for(; floorIterator != buildingModel->floors.end(); floorIterator++)
	{
		FloorModel* floorModel = *floorIterator;
		message << floorModel->GetFloorNumber() << ") " << floorModel->GetName() << "\n";
	}
	
	//return string
	return message.str();
}
