#include <iostream>
#include "add.h"
using namespace std;


/*值传递：
	定义：函数调用时，实参数值传入给形参
	注意：值传递中，形参的变化并不会影响实参
*/
int main15() {
	cout << add(1, 4) << endl;
	return 0;
}