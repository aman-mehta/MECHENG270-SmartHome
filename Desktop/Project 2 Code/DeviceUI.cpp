#include "DeviceUI.h"

//display device information
void DeviceUI::ShowDeviceInfo(string name, int Id)
{
	ostringstream info;

	info << "Welcome to [" << name << "] # " << Id << ".";

	ShowInfo(info.str());
}

//display list of commands and asks user to selct an option
int DeviceUI::GetUserCommand()
{
	cout << "\nPlease select an option from the following menu:\n";
	cout << "0) Power Mangement.\n1) Check Status.\n2) Execute Command.\n";
	cout << "Or any other number to go back.\n\nSH>";
	return GetCommand();
}

//display error showing device is not command enabled
void DeviceUI::PrintError()
{
	cout << "Sorry the device is not command enabled.\nPress any key to continue.\n";
	getch();
}
