#include <iostream>
using namespace std;

/* 字符串查找和替换：
	函数原型:
	  查找：
		1、int find(const string& str, int pos=0) const;			//查找str第一次出现位置从pos开始查找 
		2、int find(const char* s, int pos=0) const;				//查找s第一次出现位置从pos开始查找 
		3、int find(const char* s, int pos, int n) const;			//从pos位置查找s的前n个字符第一次位置 
		4、int find(const char c, int pos=0) const;					//查找字符c第一次出现位置 
		5、int rfind(const string& str, int pos=npos) const;		//查找str最后一次位置从pos开始查找 
		6、int rfind(const char* s, int pos=npos) const;			//查找s最后一次出现位置从pos开始查找 
		7、int rfind(const char* s, int pos, int n) const;			//从pos查找s的前n个字符最后一次位置 
		8、int rfind(const char c, int pos=0) const;				//查找字符c最后一次出现位置 
	  替换：
		1、string& replace(int pos, int n, const string& str):		//替换从pos开始n个字符为字符串str 
		2、string& replace(int pos, int n, const char* s);			//替换从pos开始的n个字符为字符串s
*/

//查找  常用方法
void test() {
	//find 从左往右 找到返回第一个满足条件的第一个字符的位置，找不到返回-1
	string s = "helloo C++oo";
	//找不到时：
	int index = s.find("lll");
	cout << index << endl;    //-1
	cout << s.find("lll") << endl;  //4294967295  4294967295是无符号位的整形最大值，也就是有符号位整形-1
	if (s.find("lll") == -1) {
		cout << "rTYUIop" << endl;   //rTYUIop
	}
	//找到时 
	index = s.find("oo");
	cout << "oo：" << index << endl;


	//rfind  从右往左
	index = s.rfind("lll");
	cout << index << endl;    //-1
	cout << s.rfind("lll") << endl;   //4294967295

}

//替换
void test02() {
	string s = "sdfghjkl";  //替换从pos开始的n个字符为字符串s
	s.replace(1, 3, "oo");
	cout << s << endl;   //soohjkl
}



int main() {
	test();
	//test02();
	return 0;
} 
