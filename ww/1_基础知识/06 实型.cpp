#include <iostream>
using namespace std;

/*实型（浮点型）：用于表示小数，分为两种：单精度（float）、双精度（double），二者区别在于表示的有效数字范围不同。
  数据类型			占用空间			有效数字范围
   float			  4字节				 7位有效数字
   double             8字节              15-16位有效数字
  附：C++中有效数字不单单是小数点后有几位数字。
*/
 
int main6() {
	float f = 3.1415926f;  //默认情况下，编译器会把一个小数当成双精度，如果该变量是float类型，不加f，底层需要多一步转换
	double d = 3.1415926;
	cout << f << endl;  
	cout << d << endl; //默认情况下，输出一个小数，会显示出6位有效数字
	cout << sizeof(f) << endl;
	cout << sizeof(d) << endl;

	//科学计数法
	float f1 = 3e2;  //3*10^2
	cout << f1 << endl;	
	float f2 = 3e-2;  //3*0.1^2
	cout << f2 << endl;
	return 0;
}
