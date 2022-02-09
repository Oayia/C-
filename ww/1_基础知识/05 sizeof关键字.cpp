#include <iostream>
using namespace std;

/*可利用sizeof求出数据类型占用内存大小
  语法：
	sizeof(数据类型/变量)
*/

int main5() {
	short num1 = 2;
	int num2 = 10;
	long num3 = 10;
	long long num4 = 10;
	cout << "short占用内存空间为：" << sizeof(num1) << endl;
	cout << "int占用内存空间为：" << sizeof(int) << endl;
	cout << "long占用内存空间为：" << sizeof(num3) << endl;
	cout << "long long占用内存空间为：" << sizeof(num4) << endl;
	system("pause");
	return 0;
}