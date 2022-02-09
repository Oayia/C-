#include <iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

/*	1���ڽ���������
		STL�ڽ���һЩ�������󣬷�Ϊ�����º�������ϵ�º������߼��º���
		��Щ�º����������ĵĶ����÷���һ�㺯����ȫ��ͬ
		ʹ���ڽ�����������Ҫ����ͷ�ļ�#include<functional>
	
	2�������º���  ʵ����������
		template<class T> T plus<T>			//�ӷ��º��� 
		template<class T> T minus<T>		//�����º��� 
		template<class T> T multiplies<T>	//�˷��º��� 
		template<class T> T divides<T>		//�����º��� 
		template<class T> T modulus<T>		//ȡģ�º��� 
		template<class T> T negate<T>		//ȡ���º�����negate��һԪ���㣬�������Ƕ�Ԫ����
	
	3����ϵ�º���  ��õ���greater����ΪĬ�ϵײ����less
		template<class T> bool equal toct>			//���� 
		template<class T> bool not egual to<T>		//������ 
		templatecclass T> bool greater<T>			//���� 
		template<class T> bool greater equal<T>		//���ڵ��� 
		templatecclass T> bool less<T>				//С�� 
		template<class T> bool less equal<T>		//С�ڵ���

	4���߼��º��� �����л����ò���
		template<class T> bool logical_and<T>		//�߼��� 
		template<classT> bool logical_or<t>			//�߼��� 
		template<classT> bool logical_not<T>		//�߼���
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

	//�����߼��� ������v���˵�v2�У���ִ��ȡ������
	vector<bool> v2;
	v2.resize(v.size());	//��Ҫ�ȿ��ٺÿռ�
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	myPrint1(v2);		//0 1 0 0
}

//���� greater
void test03() {
	vector<int> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(2);
	v.push_back(6);
	v.push_back(1);
	myPrint(v);			//3 5 2 6 1

	//����
	//sort(v.begin(), v.end(), MyCompare());
	//�ڽ�greater<int>()
	sort(v.begin(), v.end(), greater<int>());
	myPrint(v);			//6 5 3 2 1
}

//plus ��Ԫ�º��� �ӷ�
void test02() {
	plus<int> p;
	cout << p(2, 6) << endl;	//8
}

//negate һԪ�º��� ȡ���º���
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