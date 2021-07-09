#pragma once

#include "Db.h"

namespace std
{
	struct IdleItem
	{
		IdleItem(Db* dbPtr, size_t timestamp);
		Db* _dbPtr;
		size_t _timestamp;
	};

}
