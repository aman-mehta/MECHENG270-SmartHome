
#include "PowerUI.h"

//display power options and get input from user
int PowerUI::GetUserCommand(int status)
{	
	if (status){
		//if power is already on ask user to turn it off
		cout<< "The device is currently powered on.\nWould you like to turn it off?\n0)No\n1)Yes\n\nSH> ";
	}
	else{
		//if power is already off ask user to turn it on
		cout<< "The device is currently powered off.\nWould you like to turn it on?\n0)No\n1)Yes\n\nSH> ";
	}
	return GetCommand();
}

//display error for invalid input
void PowerUI::PrintError()
{
	cout << "Sorry your command was not recognised.\nPress any key to continue.\n";
	getch();
}
