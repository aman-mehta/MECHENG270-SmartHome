#include "CommonDefs.h"
#include "SystemHandler.h"

int main(int argc, char* argv[])
{	
	//create system handler instance
	SystemHandler* handler = new SystemHandler();

	//run the client system
	handler->Run();
	
	//must delete explicitly when "new" is used
	delete handler;

	//all is well that ends well
	return 0;
}



