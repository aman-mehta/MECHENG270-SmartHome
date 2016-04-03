#include "RoomUI.h"

//display room information
void RoomUI::ShowRoomInfo(string name, int roomNumber, int floorNumber)
{
	ostringstream info;
	
	info << "Welcome to [" << name << "] # " << floorNumber << "." << roomNumber;
	
	ShowInfo(info.str());
}

//display the list of devices and asks the user to select an option
int RoomUI::GetUserCommand(string message)
{
	cout << "\nPlease select a device from the following menu:\n";
	cout << message;
	cout << "Or any other number to go back.\n\nSH> ";
	return GetCommand();
}

//display error for offline device
void RoomUI::PrintOfflineError()
{
	cout << "The device is currently offline. Please try again later.\n";
	cout << "Press any key to continue.\n";
	getch();
}