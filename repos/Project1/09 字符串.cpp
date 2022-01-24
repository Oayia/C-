#include <iostream>
using namespace std;

/*字符串型：用于表示一串字符
  两种风格：
	1、沿用C风格字符串：char 变量名[] = "字符串值"
	2、C++风格字符串：string 变量名 = "字符串值"
*/
int main9() {
	char s1[] = "东皇太一";
	string s2 = "姬如千泷";  //老的版本可能需要添加头文件：#include <string>
	cout << s1 << endl;
	cout << s2 << endl;
	return 0;
}