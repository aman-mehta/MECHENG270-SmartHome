#include "BuildingModel.h"

BuildingModel::BuildingModel()
{
	//load building attributes
	name = SHAPI_GetBuildingName();
	address = SHAPI_GetBuildingStreetAddress();

	//load floors in the building
	loadFloors();
}

BuildingModel::~BuildingModel()
{
	//dispose all members
	disposeFloors();
}

void BuildingModel::loadFloors()
{
	//get the number of floors in this building
	int count = SHAPI_GetFloorCount();

	//iterate and load floors
	for(int index = 0; index < count; index++)
	{
		//get the name of the floor
		string floorName = SHAPI_GetFloorName(index);
		
		//create new floor entity 
		FloorModel* floorModel = new FloorModel(index, floorName);
		floors.push_back(floorModel);
	}	
}

void BuildingModel::disposeFloors()
{
	//iterate over all floors and dispose one by one
	vector<FloorModel*>::iterator floorIterator = floors.begin();
	for(; floorIterator != floors.end(); floorIterator++)
	{
		FloorModel* floorModel = *floorIterator;
		delete floorModel;
	}
}

string BuildingModel::GetStreetAddress()
{
	//returns the street address of the building
	return address;
}

