#include "CommonDefs.h"
#include "BaseUI.h"
#include "DeviceModel.h"

class CommandUI : public BaseUI
{	
public:
	//member functions
	int GetUserCommand(int maxCommand);
	void PrintError();
};
