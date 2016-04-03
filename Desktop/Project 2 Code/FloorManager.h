#include "CommonDefs.h"
#include "FloorUI.h"
#include "FloorModel.h"
#include "RoomManager.h"

class FloorManager
{
private:
	//members variables
	FloorUI* floorUI;
	FloorModel* floorModel;
	
	//private methods
	string CreateString();
public:	
	//constructor/destructor
	FloorManager(FloorModel* floorModel);
	~FloorManager();

	//member functions
	void InvokeUserInteraction();
};
