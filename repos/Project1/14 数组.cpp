#include<iostream>
using namespace std;

/*һά�������������壺
	1������ͳ�������������ڴ��еĳ��ȣ�
	2�������������ڴ��е��׵�ַ����һ������
	
  ��ά�������������壺
	1���鿴��ά������ռ�ڴ�ռ䣻
	2����ȡ��ά�����׵�ַ��
	*/

int main14(){
	//һά���鶨�巽ʽһ
	int arr1[3];
	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 3;

	//һά���鶨�巽ʽ��
	int arr2[3] = { 1, 2, 3 };
	cout << "����һά����ռ���ڴ�ռ�Ϊ��" << sizeof(arr2) << "�ֽ�" << endl;
	//һά���鶨�巽ʽ��
	int arr3[] = { 1, 2, 3 };
	for (int i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++) {
		cout << arr1[i] << endl;
	}

	//��ά���鶨�巽ʽһ
	int arr4[2][3];
	//��ά���鶨�巽ʽ��
	int arr5[2][3] = { {1,2,3},{4,5,6} };
	//��ά���鶨�巽ʽ��
	int arr6[2][3] = { 1,2,3,4,5,6 };
	cout << sizeof(arr6) << endl;


	//���ά�����׵�ַ����һ���׵�ַ����һ�е�һ��Ԫ�ص�ַ��������ͬһ����ַ
	cout << "��ά�����׵�ַ��" << int(arr6) << endl;
	cout << "��һ���׵�ַ��"<<int(arr6[0]) << endl;
	cout << "��һ�е�һ��Ԫ�ص�ַ��"<<int(&arr6[0][0]) << endl;
	cout << "�ڶ����׵�ַ��" << int(arr6[1]) << endl;
	//��ά���鶨�巽ʽ��
	int arr7[][3] = { 1,2,3,4,5,6 };
	for (int i = 0; i < sizeof(arr7)/sizeof(arr7[0]); i++) {
		for (int j = 0; j < sizeof(arr7[0]) / sizeof(arr7[0][0]); j++) {
			cout << arr7[i][j] << " ";
		}
		cout << endl;
	}
	

	return 0;
}
