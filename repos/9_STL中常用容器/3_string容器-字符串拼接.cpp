#include <iostream>
using namespace std;

/* string字符串拼接
	 函数原型:
		1、string& operator+=(const char* str);					//重载+=操作符 
		2、string& operator+=(const char c);					//重载+=操作符 
		3、string& operator+=(const string& str);				//重载+=操作符 
		4、string& append(const char* s);						//把字符串s连接到当前字符串结尾 
		5、string& append(const char* s,int n);					//把字符串s的前n个字符连接到当前字符串结尾 
		6、string& append(const string& s);						//同operator+=(const string&str) 
		7、string& append(const string& s, int pos, int n);		//字符串s中从pos开始的n个字符连接到字符串结尾
*/

void test01() {
	string str1 = "我";
	str1 += "爱玩游戏";           //1、string & operator+=(const char* str);
	cout << "str1：" << str1 << endl;

	str1 += 'o';           //2、string& operator+=(const char c);
	cout << "str1：" << str1 << endl;  

	string str2 = "uuu";
	str1 += str2;     //3、string& operator+=(const string& str);
	cout << "str1：" << str1 << endl;

	str1.append("yyyy");     //4、string& append(const char* s);
	cout << "str1：" << str1 << endl;

	str1.append("iiiii", 2);   //5、string& append(const char* s, int n);
	cout << "str1：" << str1 << endl;

	str1.append(str2);       //6、string& append(const string& s);
	cout << "str1：" << str1 << endl;

	str1.append(str2, 1, 1);     //7、string& append(const string& s, int pos, int n);
	cout << "str1：" << str1 << endl;
}

int main() {
	test01();
	return 0;
}