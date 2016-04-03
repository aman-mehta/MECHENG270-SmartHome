#include "DeviceUI.h"

void DeviceUI::ShowDeviceInfo(string name, int Id)
{
        ostringstream info;

        info << "Welcome to [" << name << "] at " << Id << ".";

        ShowInfo(info.str());
}

int DeviceUI::GetUserCommand()
{
        cout << "\nPlease select an option from the following menu:\n";
        cout << "1) Power Management\n2) Display Status\n3) Execute Command\n";
        cout << "Or press any key to go back\n";
        return GetCommand();
}
