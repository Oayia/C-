#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	1、概述:
		算法主要是由头文件<algorithm> <functional> <numeric>组成
		<algorithm>是所有STL头文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、复制、修改等等
		<numeric>体积很小，只包括几个在序列上面进行简单数学运算的模板函数
		<functional>定义了一些模板类用以声明函数对象

	2、常用遍历算法
		for_each		//遍历容器 
		transform		//搬运容器到另一个容器中，搬运的目标容器必须要提前开辟空间，否则无法正常搬运

*/

//普通函数 回调函数
void print01(int val) {
	cout << val << " ";
}

//仿函数
class Print02 {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};

//常用遍历算法  for_each
void test01() {
	vector<int>v;
	for (int i = 0; i < 8; i++) {
		v.push_back(i + 1);
	}
	//❀形参_Fn _Func：需要写一个函数，把函数名放在这，或者仿函数对象也可以
	//for_each(v.begin(), v.end(), print01);  //普通函数	输出结果：1 2 3 4 5 6 7 8
	for_each(v.begin(), v.end(), Print02());  //仿函数	输出结果：1 2 3 4 5 6 7 8

}

class Transform {
public:
	int operator()(int val) {    //❀可在搬运过程中对数据进行一些操作
		return val + 100;
	}
};

//常用遍历算法  transform
void test02() {
	vector<int>v;
	for (int i = 0; i < 8; i++) {
		v.push_back(i + 1);
	}
	vector<int>vTarget;  //目标容器
	vTarget.resize(v.size());
	transform(v.begin(), v.end(), vTarget.begin(), Transform());
	for_each(vTarget.begin(), vTarget.end(), Print02());			//101 102 103 104 105 106 107 108
}

int main() {
	//test01();
	test02();
	return 0;
}