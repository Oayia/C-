#include <iostream>
using namespace std;

struct Student {
	string name;
	int age;
};

int main20() {
	Student students[3] = { {"¶«»ÊÌ«Ò»", 100},{"ĞÇ»ê", 14} ,{"Ñ©Å®", 18} };
	for (int i = 0; i < 3; i++) {
		cout << students[i].name << " " << students[i].age << endl;
	}
	return 0;
}