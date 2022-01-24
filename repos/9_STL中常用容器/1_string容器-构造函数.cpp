#include <iostream>
using namespace std;

/* ·本质：
		string是C++风格的字符串，而本质上是一个类，维护C语言的字符串char*
   ·string和char*的区别：
		char*是一个指针
		string是一个类，类内部封装了char*，管理这个字符串是一个char*型的容器
   ·特点：
		string类内部封装了很多成员方法，如：查找find，拷贝copy，删除delete，替换replace，插入insert
		string管理char*所分配的内存，不用担心赋值越界和取值越界，由类内部进行负责
   ·string构造函数：
		构造函数原型：
			string();                    //创建一个空的字符串 例如：string str;
			string(const char* s);       //使用字符串s初始化
			string(const string& str);   //使用一个string对象初始化另一个string对象
			string(int n, char c);       //使用n个字符c初始化
*/

//string的构造函数
void test01() {
	string str1;
	string str2 = "dfghjk";
	string str3 = str2;
	string str4(6, 'o');
	str1 = str4;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
	cout << typeid(str2).name() << endl; //class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
	cout << typeid("dfghjk").name() << endl; //char const [7]
	//char c = "dfghjk";  //错误提示：const char *类型的值不能用于初始化char类型的实体
}

void test02() {
	string s1; //默认构造
	s1 = "yuio";
	cout << s1 << endl;
	
	const char* str = "Oayia";  //C语言风格字符串
	char str1[] = "hello";    //C语言风格字符串
	string s2(str);
	string s3(str1);
	cout << s2 << endl;
	cout << s3 << endl;

	string s4(s3);
	cout << s4 << endl;


}
int main() {
	//test01();
	test02();
	return 0;
}