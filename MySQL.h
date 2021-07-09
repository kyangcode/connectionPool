#include <string>
#include <mysql.h>
#include <vector>
#include <unordered_map>

namespace std 
{
	class MySQL 
	{
	public:
		MySQL(); // 构造函数
		~MySQL(); // 释放数据库连接

		void connect(string host, size_t port, string user, string passwd, string db) throw(); // 根据参数与目标数据库建立连接
		
		vector<unordered_map<string, string>> query(string sql) throw(); // 执行select
		size_t execute(string sql) throw(); // 执行update、delete、insert
	private:
		MYSQL* mysql;
	};

}
