#include <iostream>
#include <set>
using namespace std;

/*
	1、set基本概念
		set容器的所有元素都会在插入时自动被排序
		set/multiset属于关联式容器，底层结构是用二叉树实现
	
	3、set构造和赋值
		构造：
			set<T> st;				//默认构造
			set(const set& st);		//拷贝构造
		赋值：
			set& operator=(const set& st);	//重载等号操作符

	4、set大小和交换
		size();			//返回容器中元素的数目 
		empty();		//判断容器是否为空 
		swap(st);		//交换两个集合容器

	5、set插入和删除
		insert(elem);		//在容器中插入元素
		clear();			//清除所有元素 
		erase(pos);			//删除pos迭代器所指的元素，返回下一个元素的迭代器
		erase(beg, end);	//删除区间[begend)的所有元素，返回下一个元素的迭代器
		erase(elem);		//删除容器中值为elem的元素

	6、set查找和统计
		find(key);		//查找key是否存在，若存在，返回该键的元素的迭代器;若不存在，返回end迭代器; 
		count(key);		//统计key的元素个数

	7、set和multiset区别
		set不允许容器有重复的元素，而multiset允许容器有重复的元素
		set插入数据的同时会返回插入结果，表示插入成功
		multiset不会检测数据，因此可以插入重复数据

	8、pair对组创建
		功能描述：
			成对出现的数据，利用对组可以返回两个数据
		创建方式：
			pair<type, type> p(value1, value2);
			pair<type, type> p = make_pair(value1, value2);

	9、set容器排序
		set容器默认排序规则为从小到大，利用仿函数可以改变排序规则
		★对于自定义类型，set必须指定排序规则才可以插入数据，否则不知道怎么排序
			
*/

void printSet(const set<int>& s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

class Panda {
public:
	Panda(string name, int age) {
		this->name = name;
		this-> age = age;
	}
	string name;
	int age;
};

class comparePanda {
public:
	bool operator()(const Panda& p1, const Panda& p2) const {   //vs2019需要在参数列表后加const才可以
		//按照年龄 降序
		return p1.age > p2.age;
	}
};

//set容器排序 自定义数据类型
void test08() {
	set<Panda, comparePanda>s;
	Panda p1("福多多", 24);
	Panda p2("成风", 28);
	Panda p3("成浪", 25);
	Panda p4("绩笑", 21);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	for (set<Panda, comparePanda>::iterator it = s.begin(); it != s.end(); it++) {
		cout << it->name << " " << it->age << endl;
	}
}

class MyCompare {
public:
	//vs2019需要在参数列表后加const才可以
	bool operator()(int v1, int v2) const {  //第一个小括号是代表重载符号，第二个小括号是参数列表
		return v1 > v2;
	}
};

//set容器排序 内置类型指定排序规则
void test07() {
	set<int> s1;
	s1.insert(1);
	s1.insert(4);
	s1.insert(2);
	s1.insert(5);
	s1.insert(3);
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	//printSet(s);

	//指定排序规则为从小到大
	set<int, MyCompare> s2;
	s2.insert(1);
	s2.insert(4);
	s2.insert(2);
	s2.insert(5);
	s2.insert(3);
	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout<<endl;
}

//pair对组创建
void test06() {
	pair<string, int> p1("福多多", 1);
	pair<string, int> p2 = make_pair("七仔", 6);
	cout << p1.first << endl;
	cout << p1.second << endl;
	cout << p2.first << endl;
	cout << p2.second << endl;
}

//set和multiset区别
void test05() {
	set<int> s;
	pair<set<int>::iterator, bool> ret = s.insert(2);
	if (ret.second) {
		cout << "插入成功" << endl;
	}
	ret = s.insert(2);
	if (!ret.second) {
		cout << "插入失败" << endl;
	}

	multiset<int> ms;
	ms.insert(1);
	ms.insert(1);
	ms.insert(1);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


//查找和统计
void test04() {
	set<int> s;
	//插入数据 只有insert方式
	s.insert(6);
	s.insert(2);
	s.insert(7);
	s.insert(1);
	printSet(s);
	set<int>::iterator pos = s.find(7);
	if (pos != s.end()) {
		cout << "找到元素" << endl;
	}
	//对于set而言，统计结果要么是0 要么是1
	cout << s.count(7) << endl;
}

//插入和删除
void test03() {
	set<int> s;
	//插入数据 只有insert方式
	s.insert(6);
	s.insert(2);
	s.insert(7);
	s.insert(1);
	printSet(s);	//1 2 6 7

	s.erase(s.begin());
	printSet(s);	//2 6 7

	//删除 重载版本
	s.erase(7);
	printSet(s);	//2 6

	s.erase(s.begin(), s.end());	//与清空clear()等效
	printSet(s);
}

//set大小和交换
void test02() {
	set<int> s1;

	//插入数据 只有insert方式
	s1.insert(6);
	s1.insert(2);
	s1.insert(7);
	s1.insert(1);
	printSet(s1);	//1 2 6 7

	if (!s1.empty()) {
		cout << s1.size() << endl;		//4
	}

	set<int> s2;
	s2.insert(8);
	s1.swap(s2);
	printSet(s1);		//8
	printSet(s2);		//1 2 6 7
}

//set构造和赋值
void test01() {
	set<int> s1;

	//插入数据 只有insert方式
	s1.insert(6);
	s1.insert(2);
	s1.insert(7);
	s1.insert(1);

	//遍历容器
	//set容器特点，所有元素插入时候自动被排序
	//set容器不允许插入重复值 插也插不成功，也不会报错
	printSet(s1);	//1 2 6 7

	set<int> s2(s1);
	printSet(s2);	//1 2 6 7
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();
	return 0;
}