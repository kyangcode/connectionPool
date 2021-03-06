#pragma once

#include <string>
#include <mysql.h>
#include <vector>
#include <unordered_map>
#include "Db.h"

namespace std 
{
	class MySQL : public Db 
	{
	public:
		MySQL(); // 构造函数
		~MySQL(); // 释放数据库连接

		void connect(const string &host, size_t port, const string &user, const string &passwd, const string &db) throw(); // 根据参数与目标数据库建立连接
		
		vector<unordered_map<string, string>> query(const string &sql) throw(); // 执行select
		size_t execute(const string &sql) throw(); // 执行update、delete、insert
	private:
		MYSQL* mysql;
	};

}
