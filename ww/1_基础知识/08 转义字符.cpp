#include <iostream>
using namespace std;

int main8() {
	/*常用转义字符：
		换行：\n
		反斜杠：\\
		水平制表符：\t，用于对齐
	*/
	string name = "星魂";
	int age = 14;
	cout << name << "\n" << age << endl; //endl在C语言下是没有的，C++中代表换行
	cout << name << "\\" << age << endl;
	cout << name << "\t" << age << endl;
	return 0;
}


