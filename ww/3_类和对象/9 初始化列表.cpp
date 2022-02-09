#include <iostream>
using namespace std;

/*初始化列表：
	作用：初始化属性
	语法：构造函数(属性1数据类型 属性1,属性2数据类型 属性2,...):属性1(值1),属性2(值2) ... {}
	
	*/

class Animal {
public:
	//传统初始化操作
	/*Animal(int a, int b, int c) {
		m_a = a;
		m_b = b;
		m_c = c;
	}*/

	//初始化列表初始化属性
	Animal(int a, int b, int c) :m_a(a), m_b(b), m_c(c) {
		cout << "初始化" << endl;
	}
	int m_a;
	int m_b;
	int m_c;
};

int main9() {
	Animal a(1, 2, 3);
	cout << a.m_a << " " << a.m_b << " " << a.m_c << endl;
	return 0;
}