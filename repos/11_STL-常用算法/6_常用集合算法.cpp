#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
	常用集合算法：
		①set_intersection(iterator begl, iterator end1, iterator beg2, iterator end2, iterator dest);	//求两个集合的交集
																										//返回的是结束迭代器	
																										//两个集合必须是【有序序列且同为升或降】
		
		②set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);			//求两个集合的并集
																										//返回的是结束迭代器
																										//两个集合必须是【有序序列且同为升或降】
		
		③set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);	//求两个集合的交集
																										//返回的是结束迭代器	
																										//两个集合必须是【有序序列且同为升或降】
*/

void myPrint(int& val) {
	cout << val << " ";
}

//set_intersection 交集
void test() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i + 1);	//1-10
		v2.push_back(i + 5);	//5-14
	}
	/*
		交集
	*/
	vector<int>vTarget1;
	//开辟空间取小容器的size即可
	vTarget1.resize(min(v1.size(), v2.size()));
	//❀返回的是目标容器的结束迭代器
	vector<int>::iterator isEnd1 = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget1.begin());
	cout << "并集：" << endl;
	for_each(vTarget1.begin(), isEnd1, myPrint);		//5 6 7 8 9 10
	cout << endl;
	/*
		并集
	*/
	vector<int>vTarget2;
	vTarget2.resize(v1.size() + v2.size());
	vector<int>::iterator isEnd2 = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget2.begin());
	cout << "并集：" << endl;
	for_each(vTarget2.begin(), isEnd2, myPrint);		//1 2 3 4 5 6 7 8 9 10 11 12 13 14
	cout << endl;
	/*
		差集
	*/
	vector<int>vTarget3;
	vTarget3.resize(max(v1.size(), v2.size()));

	vector<int>::iterator isEnd3 = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget3.begin());
	cout << "v1和\v2的差集：" << endl;
	for_each(vTarget3.begin(), isEnd3, myPrint);		//1 2 3 4

	vector<int>::iterator isEnd3 = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget3.begin());
	cout << "v2和v1的差集：" << endl;
	for_each(vTarget3.begin(), isEnd3, myPrint);		//11 12 13 14
}

int main() {
	test();
	return 0;
}