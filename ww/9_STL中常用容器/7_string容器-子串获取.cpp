#include <iostream>
using namespace std;

/*
	从字符串中获取想要的子串：
		string substr(int pos = 0, int n = npos) const;   //返回由pos开始，截n个字符组成的字符串
*/

void test() {
	string s = "dfghjk";
	string ss = s.substr(3, 2);  //hj
	cout << ss << endl;
}

//实用操作
void test01() {
	string s = "ww@sina.com";
	//从邮件中获取用户名信息
	int index = s.find("@");
	cout << s.substr(0, index) << endl;
}

int main() {
	//test();
	test01();
	return 0;
}