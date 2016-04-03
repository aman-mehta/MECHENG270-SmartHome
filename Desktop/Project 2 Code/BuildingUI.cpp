#include "BuildingUI.h"

//Displays the building information
void BuildingUI::ShowBuildingInfo(string name, string address)
{
	ostringstream info;
	
	info << "Welcome to [" << name << "] at " << address;
	
	ShowInfo(info.str());
}

//Display the list of floors and asks the user to select an option
int BuildingUI::GetUserCommand(string message)
{
	cout << "\nPlease select a floor from the following menu:\n";
	cout << message;
	cout << "Or any other number to exit.\n\nSH> ";
	
	return GetCommand();
}
