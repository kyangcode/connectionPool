#pragma once

#include "Db.h"

namespace std
{

	struct UseItem
	{
		UseItem(Db* dbPtr);
		Db* _dbPtr;
	};
}
