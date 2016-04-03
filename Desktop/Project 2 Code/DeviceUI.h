#include "CommonDefs.h"
#include "DeviceModel.h"
#include "BaseUI.h"

class DeviceUI : public BaseUI
{
public:
	
	//member functions
	void ShowDeviceInfo(string name, int Id);
	int GetUserCommand();
	void PrintError();
};
