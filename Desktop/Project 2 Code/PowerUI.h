#include "CommonDefs.h"
#include "BaseUI.h"

#include "DeviceModel.h"

class PowerUI : public BaseUI
{
public:
	//member functions
	int GetUserCommand(int status);
	void PrintError();	
};
