#include "StatusUI.h"

//display the status of the device and wait for user input to continue
void StatusUI::GetUserCommand(string message)
{
	cout<<message;
	cout<<"Press any key to continue.\n";
	getch();
}
