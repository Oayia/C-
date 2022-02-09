#include <iostream>
#include <typeinfo>
using namespace std;

/*通过cin输入进来的值内部会自转*/
int main11() {
	//整数
	int a = 0;
	cout << "请输入一个整数：" << endl;
	cin >> a;
	cout << a << endl;
	cout << typeid(a).name() << endl;

	//小数
	float b = 3.14f;
	cout << "请输入一个小数：" << endl;
	cin >> b;
	cout << b << endl;
	cout << typeid(b).name() << endl;

	//字符串
	string c = "hhhjk";
	cout << "请输入一个字符串：" << endl;
	cin >> c;
	cout << c << endl;
	cout << typeid(c).name() << endl;
	return 0;
}