#include <iostream>
#include <list>
using namespace std;

/*
	1、list概念
		①将数据进行链式存储
		②链表（list）是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现
		③链表的组成：一系列结点
		④结点的组成：数据域和指针域，数据域用来存储数据元素，指针域用来存储下一个结点的地址
		⑤STL的列表是【双向循环列表】，尾结点的next指向头结点，头结点的prev指向尾结点
		⑥由于列表的存储方式并不是连续的内存空间，因此，列表list中的迭代器只支持前移和后移，属于【双向迭代器】
	
	2、list优缺点
		优点：
			①采用动态分配内存，不会造成内存浪费和溢出
			②链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
		缺点：
			链表灵活，空间（指针域）和时间（遍历）额外消耗较大
	
	3、list构造函数
		list<T> lst:				//list采用采用模板类实现对象的默认构造形式: 
		list(beg, end);				//构造函数将[beg, end)区间中的元素拷贝给本身
		list(n, elem);				//构造函数将n个elem拷贝给本身
		list(const list& lst);		//拷贝构造函数

	4、赋值和交换
		assign(beg ,end);					//将[beg, end)区间中的数据拷贝赋值给本身
		assign(n, elem);					//将n个elem拷贝赋值给本身
		list& operator=(const list& lst);		//重载等号操作符 
		swap(lst);		//将lst与本身的元素互换

	5、list大小操作
		size();				//返回容器中元素的个数 
		empty();			//判断容器是否为空 
		resize(num);		//重新指定容器的长度为num，若容器变长，则以默认值填充新位置，如果容器变短，则末尾超出容器长度的元素被删除
		resize(num, elem);	//重新指定容器的长度为num，若容器变长，则以elem值填充新位置，如果容器变短，则末尾超出容器长度的元素被删除

	6、插入删除
		push_back(elem);			//在容器尾部加入一个元素 pop_back();//删除容器中最后一个元素
		push_front(elem);			//在容器开头插入一个元素 pop_front();//从容器开头移除第一个元素
		insert(pos, elem);			//在pos位置插elem元素的拷贝，返回新数据的位置
		insert(pos, n, elem);		//在pos位置插入n个elem数据，无返回值
		insert(pos, beg, end);		//在pos位置插入[beg, end)区间的数据，无返回值
		clear();					//移除容器的所有数据
		erase(beg, end);			//删除[beg, end)区间的数据，返回下一个数据的位置
		erase(pos);					//删除pos位置的数据，返回下一个数据的位置
		remove(elem):				//删除容器中所有与elem值匹配的元素
	
	7、数据存取
		front();		//返回第一个元素
		back();		//返回最后一个元素

	8、反转和排序
		reverse();		//反转链表
		sort();			//链表排序

	★list有一个重要的性质，插入和删除操作都不会造成原有list迭代器的实效，但这在vector是不成立的（vector扩展造成）。STL中list和vector是两个最长被使用的容器，各有优缺点
*/

void printList(const list<int>& l) {
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

bool myCompare(int v1, int v2) {     //回调函数
	//降序 让第一个数大于第二个数
	return v1 > v2;
}

//反转和排序
void test06() {
	list<int> l;
	l.push_back(4);
	l.push_back(2);
	l.push_back(6);
	l.push_back(5);
	printList(l);		//4 2 6 5

	l.reverse();
	printList(l);		//5 6 2 4

	//❀所有不支持随机访问迭代器的容器，不可以用标准算法
	//不支持随机访问的迭代器，内部会提供对应一些算法，即成员函数
	l.sort();
	printList(l);		//2 4 5 6 默认升序

	l.sort(myCompare);   //指定规则
	printList(l);		//6 5 4 2
}

//数据存取
void test05() {
	list<int> l;
	for (int i = 0; i < 3; i++) {
		l.push_back(i);
	}
	printList(l);		//0 1 2
	cout << l.front() << endl;	//0
	cout << l.back() << endl;	//2

	//验证迭代器是不支持随机（索引）访问的
	list<int>::iterator it = l.begin();
	//it += 1; //不支持随机
	it++;
	it--;

}

//插入删除
void test04() {
	list<int> l;
	for (int i = 0; i < 3; i++) {
		l.push_back(i);
		l.push_front(i);
	}
	printList(l);		//2 1 0 0 1 2

	list<int>::iterator it = l.end();
	it--;
	l.insert(it, 666);
	printList(l);		//2 1 0 0 1 666 2

	l.insert(it, 6, 8);
	printList(l);		//2 1 0 0 1 666 8 8 8 8 8 8 2

	list<int> l2;
	l2.push_back(9);
	l2.push_back(99);
	l.insert(l.begin(), l2.begin(), l2.end());
	printList(l);			//9 99 2 1 0 0 1 666 8 8 8 8 8 8 2

	l.remove(8);
	printList(l);			//9 99 2 1 0 0 1 666 2

	l.erase(l.begin());
	printList(l);			//99 2 1 0 0 1 666 2

	l.erase(l.begin(), l.end());  //与clear()等效
	printList(l);
}

//大小操作
void test03() {
	list<int> l1;
	for (int i = 0; i < 5; i++) {
		l1.push_back(i);
	}
	printList(l1);			//0 1 2 3 4
	if (!l1.empty()) {
		cout << "元素个数：" << l1.size() << endl;		//元素个数：5
	}
	l1.resize(10);
	printList(l1);					//0 1 2 3 4 0 0 0 0 0
	l1.resize(20, 6);
	printList(l1);					//0 1 2 3 4 0 0 0 0 0 6 6 6 6 6 6 6 6 6 6

}

//赋值和交换
void test02() {
	list<int> l1;
	for (int i = 0; i < 5; i++) {
		l1.push_back(i);
	}
	printList(l1);			//0 1 2 3 4

	list<int> l2;
	l2.assign(l1.begin(), l1.end());
	printList(l2);			//0 1 2 3 4

	list<int> l3 = l1;
	printList(l3);			//0 1 2 3 4

	list<int> l4;
	l4.assign(8, 6);
	printList(l4);			//6 6 6 6 6 6 6 6

	l4.swap(l1);
	printList(l1);			//6 6 6 6 6 6 6 6
	printList(l4);			//0 1 2 3 4
}

//构造函数
void test01() {
	list<int> l1;
	for (int i = 0; i < 5; i++) {
		l1.push_back(i);
	}
	printList(l1);			//0 1 2 3 4
	
	list<int> l2(l1.begin(), l1.end());
	printList(l2);			//0 1 2 3 4

	list<int> l3(l1);
	printList(l3);			//0 1 2 3 4

	list<int> l4(8, 6);
	printList(l4);			//6 6 6 6 6 6 6 6
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