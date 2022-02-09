#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
	谓词：
		①返回bool类型的仿函数称为谓词
		②如果operator()接收一个参数，那么叫做一元谓词
		③如果operator()接收两个参数，那么叫做二元谓词
	❀_Pred代表需要一个谓词对象
*/

void printVector(const vector<int>& v) {
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


class GreaterFive {
public:
	bool operator()(int v) {	//❀一元谓词
		return v > 5;
	}
};

class MyCompare {
public:
	bool operator()(int& v1, int& v2) {		//❀二元谓词
		return v1 > v2;
	}
};

void test01() {
	vector<int> v;
	for (int i = 0; i < 8; i++) {
		v.push_back(i + 1);
	}
	printVector(v);

	//查找容器中有没有大于5的数字
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());  //返回的是满足条件的值得相应迭代器，没找到返回end迭代器
	if (it != v.end()) {
		cout << "找到了" << endl;
	}
}

void test02() {
	vector<int> v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(6);
	v.push_back(5);

	printVector(v);				//3 1 6 5
	sort(v.begin(), v.end());
	printVector(v);				//1 3 5 6  默认升序

	//使用函数对象 改变算法策略，变为降序
	sort(v.begin(), v.end(), MyCompare());
	printVector(v);				//6 5 3 1
}

int main() {
	//test01();
	test02();
	return 0;
}