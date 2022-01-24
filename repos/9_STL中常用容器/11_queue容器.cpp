#include <iostream>
#include <queue>
using namespace std;

/*
	1、queue概念
		①queue是一种先进先出（First in First Out）的数据结构，它有两个出口
		②队列容器允许从一端新增元素，从另一端移除元素
		③队列中只有队头（front）和队尾（back）才可以被外界使用，因此，队列不允许有遍历性为
		④队列中，进数据称为入队 push，出数据称为出队 pop
	
	2、构造函数:
		queue<T> que; //queue采用模板类实现，queue对象的默认构造形式 
		queue(const queue &que); //拷贝构造函数 
	
	3、赋值操作:
		queue& operator=(const queue &que); //重载等号操作符 
	
	4、数据存取:
		push(elem); //往队尾添加元素 
		pop(); //从队头移除第一个元素 
		back(); //返回最后一个元素 
		front(); /返回第一个元素 
	
	5、大小操作:
		empty(); //判断堆栈是否为空 
		size(); //返回栈的大小
*/

class Panda {
public:
	Panda(string name, int age) {
		this->name = name;
		this->age = age;
	}

	string name;
	int age;
};

void test() {
	queue<Panda> q;
	Panda p1("和花", 1);
	Panda p2("和叶", 1);
	Panda p3("福多多", 1);
	q.push(p1);
	q.push(p2);
	q.push(p3);
	if (!q.empty()) {
		cout << q.size() << endl;		//3
		cout << q.front().name << " " << q.front().age << endl;	//和花 1
		cout << q.back().name << " " << q.back().age << endl;	//福多多 1
	}
	q.pop();
	cout << q.front().name << " " << q.front().age << endl;		//和叶 1
	cout << q.size() << endl;			//2
}

int main() {
	test();
	return 0;
}