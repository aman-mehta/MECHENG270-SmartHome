#include "CommonDefs.h"
#include "BuildingUI.h"
#include "BuildingModel.h"
#include "FloorManager.h"

class BuildingManager
{
private:
	//members variables
	BuildingUI* buildingUI;
	BuildingModel* buildingModel;
	
	//private methods
	string CreateString();
public:	
	//constructor/destructor
	BuildingManager();
	~BuildingManager();

	//member functions
	void InvokeUserInteraction();
};
