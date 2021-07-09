#pragma once

#include "Db.h"
#include "MySQL.h"

namespace std
{
	class Connection : public Db
	{
	public:
		Connection();
		~Connection();

		void connect(string host, size_t port, string user, string passwd, string db) throw();		
		vector<unordered_map<string, string>> query(string sql) throw();
		size_t execute(string sql) throw();
	private:
		Db *dbPtr;
	};
}
