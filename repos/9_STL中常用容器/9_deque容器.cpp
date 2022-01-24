#include <iostream>
#include <deque>
#include <algorithm>   //标准算法头文件
using namespace std;

/*
	1、deque容器功能：
		双端数组，可以对头端进行插入删除操作
	
	2、deque与vector区别：
		vector对于头部的插入删除效率低，数据量越大，效率越低 
		deque相对而言，对头部的插入删除速度比vector快
		vector访问元素时的速度会比deque快，这和两者内部实现有关
	
	3、deque内部工作原理：
		deque内部有一个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
		中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间
	
	4、deque容器的迭代器也是支持随机访问的
	
	5、deque构造函数
		deque<T> deqT;				//默认构造形式 
		deque(beg, end);			//构造函数将[beg, end)区间中的元素拷贝给本身
		deque(n, elem);				//构造函数将n个elem拷贝给本身
		deque(const deque& deq);	//拷贝构造函数
	
	6、deque赋值操作
		deque& operator=(const deque& deq);		//重载等号操作符 
		assign(beg, end);						//将[begend)区间中的数据拷贝赋值给本身
		assign(n, elem);						//将n个elem拷贝赋值给本身
	
	7、deque大小操作  deque容器没有容量概念，它可以无限的往进放数据
		deque.empty();				//判断容器是否为空 
		deque.size();				//返回容器中元素的个数 
		deque.resize(num);			//重新指定容器的长度为num若容器变长，则以默认值填充新位置，如果容器变短，则末尾超出容器长度的元素被删除
		deque.resize(num,elem);		//重新指定容器的长度为num若容器变长，则以elem值填充新位置，如果容器变短，则末尾超出容器长度的元素被删除
	
	8、插入和删除   ☆插入和删除提供的位置是迭代器！
		两端插入操作:
			push back(elem);		//在容器尾部添加一个数据 
			push_front(elem);		//在容器头部插入一个数据 
			pop_back();				//删除容器最后一个数据 
			pop_front();			//删除容器第一个数据 
		指定位置操作:
			insert(pos, elem);			//在pos位置插入一个elem元素的拷贝，返回新数据的位置
			insert(pos, n, elem);		//在pos位置插入n个elem数据，无返回值
			insert(pos, beg, end);		//在pos位置插入[begend)区间的数据，无返回值
			clear();					//清空容器的所有数据 
			erase(beg, end);			//删除[beg, end)区间的数据，返回下一个数据的位置
			erase(pos);					//删除pos位置的数据，返回下一个数据的位置

	9、deque数据存取
		at(int idx);	//返回索引idx所指的数据 
		operator[];		//返回索引idx所指的数据 
		front();		//返回容器中第一个数据元素 
		back();			//返回容器中最后一个数据元素

	10、deque排序
		sort(iterator beg, iterator end);		//对beg和end区间内元素进行排序
		
*/

void printDeque(const deque<int>& d) {   //❀形参const修饰，然后搭配迭代器const_iterator，保证容器中的数据在被遍历时不被修改
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//deque排序
void test06() {
	deque<int> d;
	d.push_back(3);
	d.push_back(23);
	d.push_back(9);
	d.push_back(13);
	printDeque(d);			//3 23 9 13

	//❀对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序，vector容器也可以利用sort进行排序
	sort(d.begin(), d.end());
	printDeque(d);			//3 9 13 23 默认升序
}

//deque数据存取
void test05() {
	deque<int> d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	printDeque(d);					//0 1 2 3 4 5 6 7 8 9

	cout << d.front() << endl;		//0
	cout << d.back() << endl;		//9
	cout << d[0] << endl;			//0
	cout << d.at(0) << endl;		//0

}

//插入 删除
void test04() {
	deque<int> d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	printDeque(d);

	/*
		两端操作
	 */
	d.push_back(999);   //尾插
	d.push_front(666);  //头插
	printDeque(d);

	d.pop_back();   //尾删
	printDeque(d);
	d.pop_front();  //头删
	printDeque(d);

	/*
		指定位置操作
	 */
	d.insert(d.begin(), 666666);
	printDeque(d);

	d.insert(d.begin(), 3, 888);
	printDeque(d);
	
	//按照区间插入
	deque<int> d1;
	d1.push_back(2);
	d1.push_back(22);
	d1.push_front(3);
	d1.push_front(33);
	printDeque(d1);

	d.insert(d.end(), d1.begin(), d1.end());
	printDeque(d);

	//删除
	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	printDeque(d1);

	//区间方式删除
	d1.erase(d1.begin(), d1.end());
	cout << "---------------" << endl;
	printDeque(d1);
	cout << "---------------" << endl;

	d.clear();
	cout << "---------------" << endl;
	printDeque(d);
	cout << "---------------" << endl;
}

//大小操作
void test03() {
	deque<int> d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	if (!d.empty()) {
		printDeque(d);
		cout << "元素个数：" << d.size() << endl;
	}
	
	d.resize(5);
	printDeque(d);
	cout << "元素个数：" << d.size() << endl;

	d.resize(10, 6);
	printDeque(d);
	cout << "元素个数：" << d.size() << endl;
}

//赋值操作
void test02() {
	deque<int> d1;
	d1.assign(8, 6);  //assign 8个6
	printDeque(d1);

	//等号赋值
	deque<int> d2 = d1;
	printDeque(d2);

	deque<int> d3(d1.begin(), d1.end());  //assign
	printDeque(d3);
}

//构造函数
void test01() {
	deque<int> d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int> d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int> d3(8, 6);
	printDeque(d3);

	deque<int> d4(d3);
	printDeque(d4);
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	return 0;
}