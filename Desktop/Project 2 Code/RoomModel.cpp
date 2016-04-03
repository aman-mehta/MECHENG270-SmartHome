#include "RoomModel.h"

RoomModel::RoomModel(int rNumber, int fNumber, string rName)
	: NamedEntity(rName)
{
	//load room attributes
	roomNumber = rNumber;
	floorNumber = fNumber;

	//load devices in the room
	loadDevices();
}

RoomModel::~RoomModel()
{
	//dispose all members
	disposeDevices();
}

void RoomModel::loadDevices()
{
	//get a vector containing all the device id's in the room
	vector<int> idVector = *(SHAPI_GetDevices(floorNumber, roomNumber));

	//iterate and load devices
	for(unsigned int i = 0; i < idVector.size(); i++)
	{
		//get the name and ID of the device
		string deviceName = SHAPI_GetDeviceName(idVector[i]);
		int deviceId = idVector[i];
		//create new device entity 
		DeviceModel* deviceModel = new DeviceModel(deviceId, deviceName);
		devices.push_back(deviceModel);
	}	
}

void RoomModel::disposeDevices()
{
	//iterate through all devices and dispose one by one
	vector<DeviceModel*>::iterator deviceIterator = devices.begin();
	for(; deviceIterator != devices.end(); deviceIterator++)
	{
		DeviceModel* deviceModel = *deviceIterator;
		delete deviceModel;
	}
}

//get the current room number
int RoomModel::GetRoomNumber()
{
	return roomNumber;
}

//get the floor number that the room is on
int RoomModel::GetFloorNumber()
{
	return floorNumber;
}

//get the online status of the specified device ID
bool RoomModel::GetOnlineStatus(int deviceId)
{
	return SHAPI_GetDeviceOnlineStatus(deviceId);
}
