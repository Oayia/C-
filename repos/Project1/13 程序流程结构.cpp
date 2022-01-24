#include <iostream>
using namespace std;

int main13() {
	//选择结构
	int num = 0;
	cout << "请输入您的高考成绩：" << endl;
	cin >> num;
	if (num >= 650) {
		cout << "一本" << endl;
	}
	else if(num >= 500){
		cout << "二本" << endl;
	}
	else {
		cout << "三本" << endl;
	}
	
	int a = 0;
	cout << "请给该电影打分：" << endl;
	cin >> a;
	switch (a) { //只能是整型或字符型，不可以是一个区间；switch执行效率高
	case 10:
	case 9:
		cout << "经典" << endl;
		break;
	case 8:
	case 7:
		cout << "非常好" << endl;
		break;
	case 6:
	case 5:
		cout << "一般" << endl;
		break;
	default:
		cout << "烂片" << endl;
		break;
	}
	

	//循环结构
	srand((unsigned int)time(NULL)); //可能需要引入头文件#include <ctime>
	int num1 = rand()%100 +1;
	int num2 = 0;
	cout << num1 << endl;
	while (1) {
		cin >> num2;
		if (num2 > num1) {
			cout << "大了" << endl;
		}
		else if (num2 < num1) {
			cout << "小了" << endl;
		}
		else {
			cout << "猜对了" << endl;
			break;
		}
	}
	
	int num3 = 0;
	do {
		cout << num3 << endl;
		num3++;
	} while (num3 < 10);
	
	for (int i = 0; i < 10; i++) {
		cout << i << endl;
	}
	return 0;
}
