#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	常用拷贝和替换算法：
		①copy(iterator beg, iterator end, iterator dest);			//容器内指定范围的元素拷贝到另一容器中  dest目标起始迭代器
		②replace(iterator beg, iterator end, oldvalue, newvalue);	//将区间内【所有旧元素】替换成新元素
		③replace_if(iterator beg, iterator end, pred, newvalue);	//按条件替换元素，满足条件的替换成指定元素
		④swap(container c1,container c2);			//互换两个容器的元素 本质就指针的互换

*/

void myPrint(int& val) {
	cout << val << " ";
}

//copy
void test01() {
	vector<int>v;
	for (int i = 0; i < 8; i++) {
		v.push_back(i + 1);
	}
	vector<int>v1;
	for (int i = 4; i < 26; i++) {
		v1.push_back(i + 1);
	}
	//实际开发中使用少		❀一个容器赋值给另一个容器，那直接等号赋值不就直接完事了，等号还不用事先开辟空间
	//v1 = v;
	v1.resize(v.size());	
	copy(v.begin(), v.end(), v1.begin());
	for_each(v1.begin(), v1.end(), myPrint);
}

class MyPrint01 {
public:
	void operator()(int& val) {
		cout << val << " ";
	}
};

//replace
void test02() {
	vector<int>v;
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(5);
	for_each(v.begin(), v.end(), MyPrint01());	//2 4 5 5
	cout << endl;
	replace(v.begin(), v.end(), 5, 6);
	for_each(v.begin(), v.end(), MyPrint01());	//2 4 6 6
}

class Greater {
public:
	bool operator()(int& val) {
		return val > 20;
	}
};

bool test11(int& val) {
	return val > 20;
}

//replace_if
void test03() {
	vector<int>v;
	v.push_back(2);
	v.push_back(4);
	v.push_back(6);
	v.push_back(5);
	v.push_back(23);
	for_each(v.begin(), v.end(), MyPrint01());		//2 4 6 5 23
	cout << endl;
	replace_if(v.begin(), v.end(), Greater(), 666);
	for_each(v.begin(), v.end(), MyPrint01());		//2 4 6 5 666
}

//swap
void test04() {
	vector<int>v;
	v.push_back(2);
	v.push_back(4);
	v.push_back(6);
	v.push_back(5);
	v.push_back(23);
	vector<int>v1;
	cout << "交换前v1:";
	for_each(v1.begin(), v1.end(), MyPrint01());		//2 4 6 5 23
	cout << endl;
	cout << "交换前v:";
	for_each(v.begin(), v.end(), MyPrint01());		//
	cout << endl;
	
	swap(v, v1);

	cout << "交换后v1:";
	for_each(v1.begin(), v1.end(), MyPrint01());
	cout << endl;
	cout << "交换后v:";
	for_each(v.begin(), v.end(), MyPrint01());		//2 4 6 5 23

	/* 执行结果：
		 交换前v1:
		 交换前v:2 4 6 5 23
		 交换后v1:2 4 6 5 23
		 交换后v:
	*/
}

int main() {
	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}