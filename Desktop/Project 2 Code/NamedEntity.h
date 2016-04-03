#ifndef __NamedEntity__
#define __NamedEntity__

#include "CommonDefs.h"

class NamedEntity
{
protected:
	string name;
	NamedEntity();
	NamedEntity(string entityName);

public:
	string GetName();
};

#endif
