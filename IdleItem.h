#pragma once

#include "Connection.h"

namespace std
{
	struct IdleItem
	{
		Db *dbPtr;
		size_t timestamp;
	}

}
