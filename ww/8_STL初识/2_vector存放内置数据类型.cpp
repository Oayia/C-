#include <iostream>
#include <vector>
#include <algorithm>  //��׼�㷨ͷ�ļ�
using namespace std;


/* STL����õ���������vector���������Ϊ����
* 
	������vector
	�㷨��for_each
	��������vector<int>::iterator
*/

void myPrint(int val) {
	cout << val << endl;
}

void test1() {
	//����һ��vector����������
	vector<int> v;  

	//���������������  β��
	v.push_back(1);  
	v.push_back(2);
	v.push_back(3);

	//ͨ�����������������е�����
	//������ʽһ
	/*vector<int>::iterator itBegin = v.begin();  //��ʼ������ ָ�������е�һ��Ԫ��
	vector<int>::iterator itEnd = v.end();   //���������� ָ�����������һ��Ԫ�ص���һ��λ��
	while (itBegin != itEnd) {
		cout << *itBegin << endl;
		itBegin++;
	}*/

	//������ʽ��
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}

	//������ʽ��  ����STL�ṩ�����㷨
	for_each(v.begin(), v.end(), myPrint);
	
}

int main() {
	test1();
	return 0;
}