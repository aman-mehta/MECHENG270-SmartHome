#include "CommonDefs.h"
#include "RoomModel.h"
#include "BaseUI.h"

class RoomUI : public BaseUI
{
public:
	//public methods
	void ShowRoomInfo(std::string name, int roomNumber, int floorNumber);
	int GetUserCommand(string message);
	void PrintOfflineError();
};

