#include "BaseUI.h"

void BaseUI::ShowInfo(string info)
{
	//clear screen before showing the welcome message
	cout << "\n";
	int ret = system("clear");
	if(ret != 0)
	{
		//clear has failed, attempt to clear screen with vertical spaces
		cout << "X\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v";	
	}

	//show the information
	cout << "*************************************************\n";
	cout << info << "\n";
	cout << "*************************************************\n";
}

int BaseUI::GetCommand()
{
	string commandInput;
	cin >> commandInput;

	int commandId;
	
	try 
	{
		//converting from string to integers
		commandId = stoi(commandInput);
	} 
	catch (exception& ex) 
	{
		//the given string is not an integer, use default value of -1
		commandId = -1;
	}

	return commandId;
}

//taken from following source
//http://www.daniweb.com/software-development/c/threads/148447/getch-implementation-in-unix#
int BaseUI::getch()
{
    int ch;
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    cin.get();	
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); 

    return ch;
}
