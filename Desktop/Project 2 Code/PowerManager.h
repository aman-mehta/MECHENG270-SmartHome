#include "CommonDefs.h"
#include "PowerUI.h"
#include "DeviceModel.h"


class PowerManager
{
private:
	//private members
	PowerUI* powerUI;
	DeviceModel* deviceModel;
	
public:
	//constructers / destructers
	PowerManager(DeviceModel* device);
	~PowerManager();

	//member functions
	void InvokeUserInteraction();
};
