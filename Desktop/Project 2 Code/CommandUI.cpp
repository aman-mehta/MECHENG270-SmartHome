#include "CommandUI.h"

//display different command options and get the user input
int CommandUI::GetUserCommand(int maxCommand)
{
	cout<<"Please input a command to execute, accepting [0-"<<maxCommand<<"].\n";

	return GetCommand();
}

//display error for invalid commands and wait for user to continue
void CommandUI:: PrintError()
{
	cout<<"Did not recognise input.\nPress any key to continue.\n\nSH> ";
	
	getch();
}
