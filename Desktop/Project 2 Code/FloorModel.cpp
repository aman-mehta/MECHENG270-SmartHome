#include "FloorModel.h"

FloorModel::FloorModel(int fNumber, string fName)
	: NamedEntity(fName)
{
	//initialize members
	floorNumber = fNumber;
	
	//load rooms on the floor
	loadRooms();
}

FloorModel::~FloorModel()
{
	//dispose all members
	disposeRooms();
}

void FloorModel::loadRooms()
{
	//get the number of rooms on the floor
	int count = SHAPI_GetRoomCount(floorNumber);
	
	//iterate and load rooms
	for(int index = 0; index < count; index++)
	{
		//get the name of the room
		string roomName = SHAPI_GetRoomName(floorNumber, index);
		
		//create new room entity 
		RoomModel* roomModel = new RoomModel(index, floorNumber, roomName);
		rooms.push_back(roomModel);
	}	
}

void FloorModel::disposeRooms()
{
	//iterate over all rooms and dispose one by one
	vector<RoomModel*>::iterator roomIterator = rooms.begin();
	for(; roomIterator != rooms.end(); roomIterator++)
	{
		RoomModel* roomModel = *roomIterator;
		delete roomModel;
	}
}

int FloorModel::GetFloorNumber()
{
	//return floor number
	return floorNumber;
}
