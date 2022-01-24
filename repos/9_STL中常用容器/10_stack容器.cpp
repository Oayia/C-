#include <iostream>
#include <stack>
using namespace std;

/*
	1、stack概念
		stack是一种先进后出（First In Last Out,FILO）的数据结构，它只有一个出口。栈中只有顶端元素才可以被外界使用，因此，栈不允许有遍历行为
		push：入栈，pop：出栈
	
	2、构造函数:
		stack<T> stk;				//stack采用模板类实现，stack对象的默认构造形式 
		stack(const stack &stk);	//拷贝构造函数 
	
	3、赋值操作:
		stack& operator=(const stack &stk);		//重载等号操作符 
	
	4、数据存取:
		push(elem);			//向栈顶添加元素 
		pop();				//从栈顶移除第一个元素 
		top();				//返回栈顶元素 
	
	5、大小操作:
		empty(); //判断堆栈是否为空 
		size(); //返回栈的大小
*/

void test01() {
	stack<int> s;		//默认构造
	for (int i = 0; i < 5; i++) {
		s.push(i);
	}
	cout << "元素个数：" << s.size() << endl;
	//只要栈不为空，查看栈顶，并执行出栈操作
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << "元素个数：" << s.size() << endl;

}

int main() {
	test01();
	return 0;
}