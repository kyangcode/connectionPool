#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace std
{

	class Db
	{
	public:
		virtual void connect(const string &host, size_t port, const string &user, const string &passwd, const string &db) throw() = 0;
		virtual vector<unordered_map<string, string>> query(const string &sql) throw() = 0;
		virtual size_t execute(const string &sql) throw() = 0;
	};
}
