#include "MySQL.h"

namespace std
{
	MySQL::MySQL()
	{
		mysql = nullptr;
	}

	MySQL::~MySQL()
	{
		if (mysql != nullptr)
		{
			mysql_close(mysql);
		}
	}

	bool MySQL::connect(string host, size_t port, string user, string passwd, string db)
	{
		
	}

	vector<unordered_map<string, string>> query(string sql)
	{

	}

	size_t execute(string sql)
	{

	}
}
