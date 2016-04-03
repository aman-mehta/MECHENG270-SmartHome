#include "CommonDefs.h"
#include "DeviceUI.h"
#include "DeviceModel.h"
#include "PowerManager.h"
#include "StatusManager.h"
#include "CommandManager.h"

class DeviceManager
{
private:
	//members variables
	DeviceUI* deviceUI;
	DeviceModel* deviceModel;

public:	
	//constructor/destructor
	DeviceManager(DeviceModel* deviceModel);
	~DeviceManager();

	//member functions
	void InvokeUserInteraction();
};