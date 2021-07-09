#include "Connection.h"

namespace std
{
	Connection::Connection() : dbPtr(new MySQL) {}
	
	Connection::~Connection() { delete dbPtr; }

	void Connection::connect(const string &host, size_t port, const string &user, const string &passwd, const string &db) throw()
	{
		dbPtr->connect(host, port, user, passwd, db);
	}

	vector<unordered_map<string, string>> Connection::query(const string &sql) throw()
	{
		return dbPtr->query(sql);
	}

	size_t Connection::execute(const string &sql) throw()
	{
		return dbPtr->execute(sql);
	}

}
