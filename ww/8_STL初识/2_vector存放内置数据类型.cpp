#include <iostream>
#include <vector>
#include <algorithm>  //标准算法头文件
using namespace std;


/* STL中最常用的容器就是vector，可以理解为数组
* 
	容器：vector
	算法：for_each
	迭代器：vector<int>::iterator
*/

void myPrint(int val) {
	cout << val << endl;
}

void test1() {
	//创建一个vector容器，数组
	vector<int> v;  

	//向数组中添加数据  尾插
	v.push_back(1);  
	v.push_back(2);
	v.push_back(3);

	//通过迭代器访问容器中的数据
	//遍历方式一
	/*vector<int>::iterator itBegin = v.begin();  //起始迭代器 指向容器中第一个元素
	vector<int>::iterator itEnd = v.end();   //结束迭代器 指向容器中最后一个元素的下一个位置
	while (itBegin != itEnd) {
		cout << *itBegin << endl;
		itBegin++;
	}*/

	//遍历方式二
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}

	//遍历方式三  利用STL提供遍历算法
	for_each(v.begin(), v.end(), myPrint);
	
}

int main() {
	test1();
	return 0;
}