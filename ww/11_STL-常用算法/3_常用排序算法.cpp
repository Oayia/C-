#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;

/*
	常用排序算法：
		①sort(iterator beg, iteratorend， Pred);		//对容器内元素进行排序，第3个参数Pred不传默认是升序		❀_Pred 谓词或普通函数
		②random_shuffle(iterator beg, iterator end);	//洗牌 指定范围内的元素随机调整次序 
		③merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);	//容器元素合并，并存诸到另一容器中  ❀两个容器必须是有序且一致（同为降序或同为升序）
																							//beg1 容器1开始迭代器//end1容器1结束迭代器
																							//beg2 容器2开始迭代器//end2容器2结束迭代器
																							//dest 目标容器开始迭代器
		④reverse(iterator beg, iterator end);		//反转指定范围的元素

*/

void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

class MyPrint01 {
public:
	bool operator()(int v1, int v2) {
		return v1 > v2;
	}
};

bool myPrint02(int v1, int v2) {
	return v1 > v2;
}

//sort 容器内元素排序
void test01() {
	vector<int>v;
	for (int i = 0; i < 8; i++) {
		v.push_back(i + 1);
	}
	printVector(v);		//1 2 3 4 5 6 7 8
	//降序
	//sort(v.begin(), v.end(), MyPrint01());	//仿函数MyPrint01()
	//sort(v.begin(), v.end(), myPrint02);		//普通函数myPrint02
	sort(v.begin(), v.end(), greater<int>());	//内建函数对象：greater<int>()，所属头文件<functinal>
	printVector(v);		//8 7 6 5 4 3 2 1

}

//random_shuffle 洗牌
void test02() {
	srand((unsigned int)time(NULL));  //❀随机数种子
	vector<int>v;
	for (int i = 0; i < 8; i++) {
		v.push_back(i + 1);
	}
	printVector(v);		//1 2 3 4 5 6 7 8
	random_shuffle(v.begin(), v.end());
	printVector(v);
}

void myPrint(int& val) {
	cout << val << " ";
}

void test03() {
	vector<int>v1;
	vector<int>v2;
	vector<int>vTarget;
	for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
	}
	for (int i = 6; i < 12; i++) {
		v2.push_back(i);
	}
	vTarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), myPrint);		//1 2 3 4 6 7 8 9 10 11
}

void test04() {
	vector<int>v;
	for (int i = 6; i < 12; i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), myPrint);		//6 7 8 9 10 11
	cout << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);		//11 10 9 8 7 6
}

int main() {
	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}