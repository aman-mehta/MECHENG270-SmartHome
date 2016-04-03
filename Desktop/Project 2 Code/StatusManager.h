 #include "CommonDefs.h"
 #include "StatusUI.h"
 #include "DeviceModel.h"


class StatusManager
{
private:
	//private members
	DeviceModel* deviceModel;
	StatusUI* statusUI;
	
	//private methods
	string CreateString();
	
public:
	//constructor / destructor
	StatusManager(DeviceModel* device);
	~StatusManager();
	
	//member functions
	void InvokeUserInteraction();
};
