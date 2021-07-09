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

	void MySQL::connect(string host, size_t port, string user, string passwd, string db) throw()
	{
		mysql = mysql_init(nullptr);
		if (mysql_real_connect(mysql, host.c_str(), user.c_str(), passwd.c_str(), db.c_str(), port, nullptr, 0) == nullptr)
		{
			throw string("connect error:") + mysql_error(mysql);
		}
	}

	vector<unordered_map<string, string>> MySQL::query(string sql) throw()
	{
		if (mysql_query(mysql, sql.c_str()) != 0)
		{
			throw string("query error:") + mysql_error(mysql);
		}
	
		MYSQL_RES *res = mysql_store_result(mysql);
		if (res == nullptr)
		{
			throw string("query error:") + mysql_error(mysql);
		}

		size_t rowNum = mysql_num_rows(res);
		size_t fieldNum = mysql_num_fields(res);
		
		MYSQL_FIELD *fields = mysql_fetch_fields(res);
		
		vector<unordered_map<string, string>> data;
		for (int i = 0; i < rowNum; i++)
		{
			MYSQL_ROW row = mysql_fetch_row(res);
			if (row == nullptr)
			{
				throw string("query error:") + mysql_error(mysql);
			}
			
			unordered_map<string, string> map;
			for (int j = 0; j < fieldNum; j++)
			{
				map.insert(pair<string, string>(fields[j].name, row[j]));
			}		
			data.push_back(map);					
		}
		return data;	
	}

	size_t MySQL::execute(string sql) throw()
	{
		if (mysql_query(mysql, sql.c_str()) != 0)
		{
			throw string("execute error:") + mysql_error(mysql);
		}
		return static_cast<size_t>(mysql_affected_rows(mysql));
	}
}
