#include <iostream>
#include <vector>
using namespace std;


//ÈÝÆ÷Ç¶Ì×ÈÝÆ÷
void test01() {
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	v1.push_back(1);
	v1.push_back(11);
	v1.push_back(111);
	v2.push_back(2);
	v2.push_back(22);
	v2.push_back(222);
	v3.push_back(3);
	v3.push_back(33);
	v3.push_back(333);

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			cout << *vit << endl;
		}
	}
}
int main() {
	test01();
	return 0;
}