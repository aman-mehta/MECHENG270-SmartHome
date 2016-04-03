#include "CommonDefs.h"
#include "BuildingManager.h"

class SystemHandler
{
public:
	//members variables
	BuildingManager* buildingManager;
	
	//constructor/destructor
	SystemHandler();		
	~SystemHandler();

	//members functions
	void Run();
};
