#include<iostream>
using namespace std;

/*一维数组数组名意义：
	1、用于统计整个数组在内存中的长度；
	2、代表数组在内存中的首地址，是一个常量
	
  二维数组数组名意义：
	1、查看二维数组所占内存空间；
	2、获取二维数组首地址；
	*/

int main14(){
	//一维数组定义方式一
	int arr1[3];
	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 3;

	//一维数组定义方式二
	int arr2[3] = { 1, 2, 3 };
	cout << "整个一维数组占用内存空间为：" << sizeof(arr2) << "字节" << endl;
	//一维数组定义方式三
	int arr3[] = { 1, 2, 3 };
	for (int i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++) {
		cout << arr1[i] << endl;
	}

	//二维数组定义方式一
	int arr4[2][3];
	//二维数组定义方式二
	int arr5[2][3] = { {1,2,3},{4,5,6} };
	//二维数组定义方式三
	int arr6[2][3] = { 1,2,3,4,5,6 };
	cout << sizeof(arr6) << endl;


	//★二维数组首地址、第一行首地址、第一行第一个元素地址这三者是同一个地址
	cout << "二维数组首地址：" << int(arr6) << endl;
	cout << "第一行首地址："<<int(arr6[0]) << endl;
	cout << "第一行第一个元素地址："<<int(&arr6[0][0]) << endl;
	cout << "第二行首地址：" << int(arr6[1]) << endl;
	//二维数组定义方式四
	int arr7[][3] = { 1,2,3,4,5,6 };
	for (int i = 0; i < sizeof(arr7)/sizeof(arr7[0]); i++) {
		for (int j = 0; j < sizeof(arr7[0]) / sizeof(arr7[0][0]); j++) {
			cout << arr7[i][j] << " ";
		}
		cout << endl;
	}
	

	return 0;
}
