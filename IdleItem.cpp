#include "IdleItem.h"

namespace std
{
	IdleItem::IdleItem(Db* dbPtr, size_t timestamp) : _dbPtr(dbPtr), _timestamp(timestamp) {}
}
