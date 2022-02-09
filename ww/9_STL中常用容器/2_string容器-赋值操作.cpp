#include <iostream>
using namespace std;

/*
	赋值的函数原型:
		1、string& operatod=(const char* s);		//const char*类型字符串赋值给当前的字符串 
		2、string& operator=(const string& s);		//把字符串s赋给当前的字符串 
		3、string& operator=(char c);				//字符赋值给当前的字符串 
		4、string& assign(const char* s);			//把字符串s赋给当前的字符串 
		5、string& assign(const char* s,int n);	    //把字符串s的前n个字符赋给当前的字符串 
		6、string& assign(const string& s);			//把字符串s赋给当前字符串 
		7、string& assign(int n, char c);			//用n个字符c赋给当前字符串
	
	一般等号就够用了（前两个，第三个一般都不会这么去写），成员函数assign的方式了解即可
*/

void test1() {
	string str1;
	str1 = "福多多";  //1、string& operatod=(const char* s);  const char*类型字符串赋值给当前的字符串
	cout << "str1：" << str1 << endl;

	string str2;
	str2= str1;  //2、string& operator=(const string& s);	把字符串s赋给当前的字符串 
	cout << "str2：" << str2 << endl;

	string str3;
	str3 = 'o';  //3、string& operator=(char c);   字符赋值给当前的字符串 
	cout << "str3：" << str3 << endl; 

	string str4;
	str4.assign("Oayia");  //4、string& assign(const char* s);  把字符串s赋给当前的字符串 
	cout << "str4：" << str4 << endl;

	string str5; 
	str5.assign("hjdfghj", 3);       //5、string& assign(const char* s,int n);  把字符串s的前n个字符赋给当前的字符串
	cout << "str5：" << str5 << endl; 

	string str6;
	str6.assign(str1);         //6、string& assign(const string& s);	 把字符串s赋给当前字符串 
	cout << "str6：" << str6 << endl;

	string str7;
	str7.assign(9, 'u');   //7、string & assign(int n, char c);  用n个字符c赋给当前字符串
	cout << "str7：" << str7 << endl;
}

int main() {
	test1();
	return 0;
}