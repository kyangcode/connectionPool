#pragma once

#include "Db.h"
#include "IdleItme.h"
#include "Connection.h"
#include <list>

namespace std
{
	class ConnectionPool
	{
	public:
		ConnectionPool(size_t initSize, size_t maxSize, size_t maxIdleTimeout, size_t maxWaitTimeout);
		~ConnectionPool();

		Db *allocate();
		void deallocate(Db *dbPtr);
	private:
		list<IdleItem*> _idleList; // 空闲连接链表
		list<UseItem*> _useList; // 已分配连接链表
		
		size_t _initSize; // 初始连接数量
		size_t _maxSize; // 最大连接数量
		size_t _maxIdleTimeout; // 最大空闲时间
		size_t _maxWaitTimeout; // 最大等待时间

		void checkAvailble(); // 检测连接是否可用
		void checkCanDestory(); // 检测连接是否可以释放
		void checkEnough(); // 检测连接数如果小于初始连接数，则去创建
	};


}
