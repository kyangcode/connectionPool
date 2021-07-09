#include "Connection.h"

namespace std
{
	Connection::Connection() : dbPtr(new MySQL) {}
	
	Connection::~Connection() { delete dbPtr; }

	void Connection::connect(string host, size_t port, string user, string passwd, string db) throw()
	{
		dbPtr->connect(host, port, user, passwd, db);
	}

	vector<unordered_map<string, string>> Connection::query(string sql) throw()
	{
		return dbPtr->query(sql);
	}

	size_t Connection::execute(string sql) throw()
	{
		return dbPtr->execute(sql);
	}

}
