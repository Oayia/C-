#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

/*
	算数生成算法：
		概念：
			算术生成算法属于小型算法，使用时包含的头文件为#include<numeric>
		算法：
			①accumulate(iterator beg, iterator end, value);	//计算容器元素累计总和  value：起始累加值，不需要传0即可
			②fill(iterator beg, iterator end, value);			//向容器中填充元素 value：填充的值
*/

void test01() {
	vector<int>v;
	for (int i = 0; i < 100; i++) {
		v.push_back(i + 1);
	}
	int sum = accumulate(v.begin(), v.end(), 1000); //6050
	cout << sum << endl;
}

void myPrint(int& val) {
	cout << val << " ";
}

void test02() {
	vector<int>v;
	v.resize(10);

	//❀后期重新填充
	fill(v.begin(), v.end(), 6);
	for_each(v.begin(), v.end(), myPrint);	//6 6 6 6 6 6 6 6 6 6
}

int main() {
	//test01();
	test02();
	return 0;
}