#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	常用查找算法：
		①find(iterator beg, iterator end, value);		//查找【指定元素】，找到返回指定元素的迭代器，查不到返回迭代器end()
		②find_if(iterator beg, iterator end, Pred);	//按【条件查找】元素，找到返回指定位置迭代器，找不到返回结束迭代器位置，beg：开始迭代器，end：结束迭代器 Pred：函数或者谓词
		③adjacent_find(iterator beg, iterator end);	//查找【相邻重复】元素返回相邻元素的第一个位置的迭代器，没有返回end迭代器
		④bool binary_search(iterator beg, iterator end,value);		//二分查找法 查找指定的元素，查到返回true否则false。 ❀注意:在无序序列中不可用
		⑤count(iterator beg, iterator end, value);		//统计元素出现次数
		⑥count_if(iterator beg, iterator end, Pred);	//按条件统计元素出现次数 _Pred谓词
*/

class Dog {
public:
	Dog(string name, int age) {
		this -> name = name;
		this->age = age;
	}
	string name;
	int age;
};

class MyFind02 {
public:
	bool operator()(Dog& val) {
		return val.age >= 2;
	}
};

//count_if 自定义数据类型
void test10() {
	vector<Dog>v;
	v.push_back(Dog("哮天犬", 100));
	v.push_back(Dog("哈士奇", 2));
	v.push_back(Dog("巴哥", 1));
	int c = count_if(v.begin(), v.end(), MyFind02());
	cout << c << endl;	//2
}

class MyFind {
public:
	bool operator()(int& val) {
		return val > 5;
	}
};

//count_if 内置数据类型
void test09() {
	vector<int>v;
	v.push_back(2);
	v.push_back(5);
	v.push_back(7);
	v.push_back(28);
	v.push_back(74);
	int c = count_if(v.begin(), v.end(), MyFind());
	cout << c << endl;	//3
}

class Person {
public:
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	bool operator==(const Person& p) {  //重载==
		return p.age == this->age;
	}
	string name;
	int age;
};

//count 自定义数据类型
void test08() {
	vector<Person>v;
	v.push_back(Person("东皇太一", 24));
	v.push_back(Person("少司命", 13));
	v.push_back(Person("星魂", 12));
	v.push_back(Person("韩非", 18));
	v.push_back(Person("雪女", 18));
	v.push_back(Person("高渐离", 19));
	v.push_back(Person("姬如千泷", 18));
	v.push_back(Person("天明", 9));

	//统计有没有和大司命同岁的人的个数
	int c = count(v.begin(), v.end(), Person("大司命", 18));
	cout << c << endl;  //3
}


//count 内置数据类型
void test07() {
	vector<int>v;
	v.push_back(8);
	v.push_back(2);
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	v.push_back(4);
	int c = count(v.begin(), v.end(), 5);
	cout << c << endl;		//3
}

//binary_search 二分查找法
void test06() {
	vector<int>v;
	for (int i = 0; i < 8; i++) {
		v.push_back(i + 1);
	}
	//前提是有序序列 不然不准
	bool res = binary_search(v.begin(), v.end(), 6);
	cout << res << endl;	//1
}

//adjacent_find
void test05() {
	vector<int>v;
	v.push_back(5);
	v.push_back(1);
	v.push_back(7);
	v.push_back(3);
	v.push_back(7);
	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());
	if (pos != v.end()) {
		cout << "找到了" << endl;
		cout << *pos << endl;
	}
	else {
		cout << "没找到" << endl;
	}
}

class Panda {
public:
	Panda(string name, int age) {
		this->name = name;
		this->age = age;
	}
	//❀重载==号 底层find知道如何对比panda数据类型
	bool operator==(const Panda& p)  {
		if (p.name == name && p.age == age) {
			return true;
		}
	}

	string name;
	int age;
};

//普通函数
bool myFind(Panda& p) {
	return p.age > 1;
}

class Greater2 {
public:
	bool operator()(Panda& p) {
		return p.age > 1;
	}
};

//find_if 自定义数据类型
void test04() {
	vector<Panda>v;
	Panda p1("福多多", 1);
	Panda p2("和花", 2);
	Panda p3("成实", 3);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	vector<Panda>::iterator pos = find_if(v.begin(), v.end(), myFind);
	//vector<Panda>::iterator pos = find_if(v.begin(), v.end(), Greater2());
	if (pos != v.end()) {
		cout << "找到了" << endl;
		cout << pos->name << " " << pos->age << endl;
	}
}

//普通函数
int GreaterFive01(int val) {
	return val > 5;
}

//仿函数
class GreaterFive02 {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

//find_if 内置数据类型
void test03() {
	vector<int>v;
	v.push_back(9);
	v.push_back(3);
	v.push_back(5);
	v.push_back(4);
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive01);
	//vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive02());
	if (pos != v.end()) {
		cout << "找到了" << endl;
	}
}

//find 自定义数据类型
void test02() {
	vector<Panda>v;
	Panda p1("福多多", 1);
	Panda p2("和花", 2);
	Panda p3("成实", 3);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	vector<Panda>::iterator pos = find(v.begin(), v.end(), p1);
	if (pos != v.end()) {
		cout << "找到了" << endl;
	}
}

//find 内置数据类型
void test01() {
	vector<int>v;
	v.push_back(9);
	v.push_back(3);
	v.push_back(5);
	v.push_back(4);
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos != v.end()) {
		cout << "找到了" << endl;
	}
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	test10();
	return 0;
}