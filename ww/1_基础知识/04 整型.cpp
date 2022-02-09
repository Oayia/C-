#include <iostream>
using namespace std;

/* C++规定在创建一个变量或常量时，必须要指定相应的数据类型，否则无法给变量分配内存
	数据类型				占用空间													取值范围
	short（短整型）			2字节													（-2^15，2^15-1）
	int（整型）				4字节													（-2^31，2^31-1）
	long（长整型）			Windows为4字节，Linux为4字节（32位），8字节（64位）		（-2^31，2^31-1）
	long long（长长整型）	8字节                                                   （-2^63，2^63-1）
  整型大小比较：short < int <= long <= long long

  数据类型存在的意义：
	给变量分配合适的内存空间
*/
int main4() {
	short num1 = 2;
	int num2 = 10;
	long num3 = 10;
	long long num4 = 10;
	cout << "num1：" << num1 << endl;
	cout << "num2：" << num2 << endl;
	cout << "num3：" << num3 << endl;
	cout << "num4：" << num4 << endl;
	system("pause");
	return 0;
}