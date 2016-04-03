#include "SystemHandler.h"

SystemHandler::SystemHandler()
{
	cout<<"Initializing, please wait! ... \n";

	//Smart Home API must be initialized before any calls
	SHAPI_Initialize();

	//instansiate all members
	buildingManager = new BuildingManager();

	cout<<"Done.";
}

SystemHandler::~SystemHandler()
{
	//dispose all members
	delete buildingManager;

	//Smart Home API must be shutdown at the end of the execution
	SHAPI_Dispose();
}

void SystemHandler::Run()
{
	//invoke the main user interaction
	buildingManager->InvokeUserInteraction();
}

