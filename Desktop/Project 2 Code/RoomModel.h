#ifndef __RoomModelEntity__
#define __RoomModelEntity__

#include "CommonDefs.h"
#include "DeviceModel.h"

class RoomModel : public NamedEntity
{
private:
	
	//private attributes
	int roomNumber;
	int floorNumber;
	
	//private methods
	void loadDevices();
	void disposeDevices();

public:
	vector<DeviceModel*> devices;

	//constructor/destructor
	RoomModel(int roomNumber, int floorNumber, string roomName);
	~RoomModel();

	//member functions
	int GetRoomNumber();
	int GetFloorNumber();
	bool GetOnlineStatus(int deviceId);
};

#endif

