#include <iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

/*	1、内建函数对象：
		STL内建了一些函数对象，分为算数仿函数、关系仿函数、逻辑仿函数
		这些仿函数所产生的的对象，用法和一般函数完全相同
		使用内建函数对象，需要引入头文件#include<functional>
	
	2、算数仿函数  实现四则运算
		template<class T> T plus<T>			//加法仿函数 
		template<class T> T minus<T>		//减法仿函数 
		template<class T> T multiplies<T>	//乘法仿函数 
		template<class T> T divides<T>		//除法仿函数 
		template<class T> T modulus<T>		//取模仿函数 
		template<class T> T negate<T>		//取反仿函数，negate是一元运算，其他都是二元运算
	
	3、关系仿函数  最常用的是greater，因为默认底层就是less
		template<class T> bool equal toct>			//等于 
		template<class T> bool not egual to<T>		//不等于 
		templatecclass T> bool greater<T>			//大于 
		template<class T> bool greater equal<T>		//大于等于 
		templatecclass T> bool less<T>				//小于 
		template<class T> bool less equal<T>		//小于等于

	4、逻辑仿函数 开发中基本用不到
		template<class T> bool logical_and<T>		//逻辑与 
		template<classT> bool logical_or<t>			//逻辑或 
		template<classT> bool logical_not<T>		//逻辑非
*/

void myPrint(const vector<int>& v) {
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void myPrint1(const vector<bool>& v) {
	for (vector<bool>::const_iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

class MyCompare {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

void test04() {
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(true);
	myPrint1(v);		//1 0 1 1

	//利用逻辑非 将容器v搬运到v2中，并执行取反操作
	vector<bool> v2;
	v2.resize(v.size());	//需要先开辟好空间
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	myPrint1(v2);		//0 1 0 0
}

//大于 greater
void test03() {
	vector<int> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(2);
	v.push_back(6);
	v.push_back(1);
	myPrint(v);			//3 5 2 6 1

	//降序
	//sort(v.begin(), v.end(), MyCompare());
	//内建greater<int>()
	sort(v.begin(), v.end(), greater<int>());
	myPrint(v);			//6 5 3 2 1
}

//plus 二元仿函数 加法
void test02() {
	plus<int> p;
	cout << p(2, 6) << endl;	//8
}

//negate 一元仿函数 取反仿函数
void test01() {
	negate<int> n;
	cout << n(50) << endl;		//-50
	cout << n(2) << endl;		//-2
	cout << n(4) << endl;		//-4
}


int main() {
	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}