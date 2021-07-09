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

		void connect(const string &host, size_t port, const string &user, const string &passwd, const string &db) throw();		
		vector<unordered_map<string, string>> query(const string &sql) throw();
		size_t execute(const string &sql) throw();
	private:
		Db *dbPtr;
	};
}
