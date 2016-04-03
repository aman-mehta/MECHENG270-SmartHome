#ifndef __BuildingModelEntity__
#define __BuildingModelEntity__

#include "CommonDefs.h"
#include "FloorModel.h"

class BuildingModel : public NamedEntity
{
private:
	string address;
	void loadFloors();
	void disposeFloors();

public:
	vector<FloorModel*> floors;

	//constructor/destructor
	BuildingModel();
	~BuildingModel();

	//member functions
	string GetStreetAddress();

};

#endif
