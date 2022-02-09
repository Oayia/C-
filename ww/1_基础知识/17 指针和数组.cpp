#include <iostream>
using namespace std;

int main17() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p = arr;
	for (int i = 0; i < 10; i++) {
		//cout << arr[i] << endl;
		cout << *p << endl;
		p++;
	}
	return 0;
}