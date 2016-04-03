#include "DeviceModel.h"

DeviceModel::DeviceModel(int dNumber, string dName)
	: NamedEntity(dName)
{
	//load device attributes
	deviceId = dNumber;
}

//return the device ID
int DeviceModel::GetId()
{
	return deviceId;
}

//return the power status of the device
bool DeviceModel::GetPowerStatus()
{
	return SHAPI_GetDevicePoweredOn(deviceId);
}

//return the online status of the device
bool DeviceModel::GetOnlineStatus()
{
	return SHAPI_GetDeviceOnlineStatus(deviceId);
}

//check if device is text enabled
bool DeviceModel::GetTextEnabled()
{
	return SHAPI_IsTextEnabled(deviceId);
}

//check if the device is command enabled
bool DeviceModel::GetCommandEnabled()
{
	return SHAPI_IsCommandEnabled(deviceId);
}

//check if the device is safety related
bool DeviceModel::GetSafetyRelated()
{
	return SHAPI_IsSafetyRelated(deviceId);
}

//return the text status of the device
string DeviceModel::GetTextStatus()
{
	return SHAPI_GetTextStatus(deviceId);
}

//return the safety status of the device
bool DeviceModel::GetSafetyStatus()
{
	return SHAPI_GetSafetyStatus(deviceId);
}

//execute a  specific command on the device
bool DeviceModel::ExecuteCommand(int commandId)
{
	return SHAPI_ExecuteCommand(deviceId, commandId);
}

//return the max command number of the device
int DeviceModel::GetMaxCommand()
{
	return SHAPI_GetMaxCommandId(deviceId);
}

//set the power status of the device
bool DeviceModel::SetPower(bool newStatus)
{
	return SHAPI_SetDevicePoweredOn(deviceId, newStatus);
}