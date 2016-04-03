#include "FloorUI.h"

//Displays floor information
void FloorUI::ShowFloorInfo(string name, int floorNumber)
{
	ostringstream info;

	info << "Welcome to [" << name << "] # " << floorNumber;

	ShowInfo(info.str());
}

//Display the list of rooms and asks the user to select an option
int FloorUI::GetUserCommand(string message)
{
	cout << "\nPlease select a room from the following menu:\n";
	cout << message;
	cout << "Or any other number to go back.\n\nSH> ";
	
	return GetCommand();
}
