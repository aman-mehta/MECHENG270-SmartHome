#ifndef __DeviceModelEntity__
#define __DeviceModelEntity__

#include "CommonDefs.h"

class DeviceModel : public NamedEntity
{
private:

	//private attributes
	int deviceId;

public:
	//constructor
	DeviceModel(int deviceId, string deviceName);
	
	//member functions
	int GetId();
	bool GetPowerStatus();
	bool GetOnlineStatus();
	bool GetTextEnabled();
	bool GetCommandEnabled();
	bool GetSafetyRelated();
	string GetTextStatus();
	bool GetSafetyStatus();
	bool ExecuteCommand(int commandId);
	int GetMaxCommand();
	bool SetPower(bool newStatus);

};
#endif
