#include "MySQL.h"
#include <iostream>
using namespace std;

int main()
{
	try 
	{
		MySQL mysql;
		mysql.connect("127.0.0.1", 3306, "root", "yangke", "test");
		
		/*string sql = "insert into t3(a, b) values(1, 1)";
		for (int i = 0; i < 10000; i++)
		{
			size_t affectedRows = mysql.execute(sql);
			cout << "影响的行数为:" << affectedRows << endl;
		}*/
		string sql = "select * from t2";
		vector<unordered_map<string, string>> data = mysql.query(sql);
		
		auto iter = data.begin();
		for (; iter != data.end(); iter++)
		{
			for (auto ele : *iter)
			{
				cout << ele.first << ":" << ele.second << "\t";
			}
			cout << endl;
		}
	}
	catch(string s)
	{
		cout << s << endl;
	}
	return 0;
}
