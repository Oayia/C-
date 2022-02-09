#include <iostream>
using namespace std;

/*
	字符串比较是每一个字符的ASCII码逐个做对比，最终有三种结果：
	= 返回 0
	> 返回 1
	< 返回 -1

	函数原型：
		int compare(const string& s) const		//与字符串s比较
		int compare(const char* s) const		//与字符串s比较
*/

void test() {  //❀字符串对比主要是用于判断是否相等
	string s1 = "hello";
	string s2 = "xello";
	int res = s1.compare(s2);
	cout << res << endl;           //-1
}

int main() {
	test();
	return 0;
}