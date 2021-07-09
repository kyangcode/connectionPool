#include "ConnectionPool.h"

namespace std
{
	ConnectionPool::ConnectionPool(size_t initSize, size_t maxSize, size_t maxIdleTimeout, size_t maxWaitTimeout)
		: _initSize(initSize)
		, _maxSize(maxSize)
		, _maxIdleTimeout(maxIdleTimeout)
		, _maxWaitTimeout(maxWaitTimeout)
	{
		// 启动检测线程	
	}

	ConnectionPool::~ConnectionPool()
	{
	}

	Db* ConnectionPool::allocate()
	{
		if (_idleList.size() > 0)
		{
			IdleItem* itemPtr = _idleList.front();
			_idleList.pop_front();

			_useList.push_back(itemPtr->dbPtr);
			return ptr;
		}

		if (_idleList.size() + _useList.size() < _maxSize)
		{
			try
			{
				Db* dbPtr = new Connection;
				dbPtr->connection();

				_useList.push_back(dbPtr);
				return dbPtr;
			}
			catch (const string &s)
			{
				cout << s << endl;
			}
		}

		
	}	

	void ConnectionPool::deallocate(Db *dbPtr)
	{
		
	}

}
