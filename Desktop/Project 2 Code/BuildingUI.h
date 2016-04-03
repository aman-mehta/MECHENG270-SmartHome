#include "CommonDefs.h"
#include "FloorModel.h"
#include "BaseUI.h"

class BuildingUI : public BaseUI
{
public:
	//members functions
	void ShowBuildingInfo(string name, string address);
	int GetUserCommand(string message);
};

