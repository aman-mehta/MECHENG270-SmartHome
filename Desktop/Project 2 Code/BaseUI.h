#ifndef __BaseUIDefinition__
#define __BaseUIDefinition__

#include "CommonDefs.h"

class BaseUI
{
protected:
	//members functions
	void ShowInfo(string message);
	int GetCommand();
	int getch();
};

#endif
