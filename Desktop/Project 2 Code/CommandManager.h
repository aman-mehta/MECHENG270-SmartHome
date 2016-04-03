#include "CommonDefs.h"
#include "CommandUI.h"
#include "DeviceModel.h"

class CommandManager
{
private:
	//private members
	DeviceModel* deviceModel;
	CommandUI* commandUI;
	
public:
	//contructor / destructor
	CommandManager(DeviceModel* device);
	~CommandManager();
	
	//member functions
	void InvokeUserInteraction();
};
