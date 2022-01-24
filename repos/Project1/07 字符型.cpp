#include <iostream>
using namespace std;

int main7() {
	/*注意：
		1、只能是单个字符且使用单引号；
		2、C/C++中字符型变量只占用1个字符；
		3、字符型变量并不是把字符本身放进内存中存储，而是将对应的ASCII编码放入存储单元*/
	char ch = 'w'; 
	cout << ch << endl;
	cout << int(ch) << endl; //字符变量对应的ASCII编码
	cout << "内存所占内存大小：" << sizeof(ch) << "字节" << endl;

	//char ch1 = "w"; //错误提示：const char *类型的变量不能用于初始化char类型的实体
	//char ch2 = 'fghjkl'; //错误提示：字符常量中的字符过多
	system("pause");
	return 0;
}