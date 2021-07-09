#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace std
{

	class Db
	{
	public:
		virtual void connect(string host, size_t port, string user, string passwd, string db) throw() = 0;
		virtual vector<unordered_map<string, string>> query(string sql) throw() = 0;
		virtual size_t execute(string sql) throw() = 0;
	};
}
