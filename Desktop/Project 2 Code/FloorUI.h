#include "CommonDefs.h"
#include "FloorModel.h"
#include "BaseUI.h"

class FloorUI : public BaseUI
{
public:
	//members functions
	void ShowFloorInfo(string name, int floorNumber);
	int GetUserCommand(string message);
};
