#ifndef __FloorModelEntity__
#define __FloorModelEntity__

#include "CommonDefs.h"
#include "RoomModel.h"

class FloorModel : public NamedEntity
{
	
private:
	
	//private attributes
	int floorNumber;
	void loadRooms();
	void disposeRooms();
	
public:
	vector<RoomModel*> rooms;
	
	//constructor/destructor
	FloorModel(int floorNumber, string floorName);
	~FloorModel();

	//member functions
	int GetFloorNumber();
};

#endif
