#include "CommonDefs.h"
#include "RoomUI.h"
#include "RoomModel.h"
#include "DeviceManager.h"

class RoomManager
{
private:
	//members variables
	RoomUI* roomUI;
	RoomModel* roomModel;
	
	//private methods
	string CreateString();
	bool CheckDeviceId(int Id);
	int GetPosition(int Id);

public:	
	//constructor/destructor
	RoomManager(RoomModel* roomModel);
	~RoomManager();

	//member functions
	void InvokeUserInteraction();
};
