#include "NamedEntity.h"

NamedEntity::NamedEntity()
{
	name = "";
}

NamedEntity::NamedEntity(string entityName)
{
	name = entityName;
}

string NamedEntity::GetName()
{
	return name;
}

