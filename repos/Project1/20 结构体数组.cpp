#include <iostream>
using namespace std;

struct Student {
	string name;
	int age;
};

int main20() {
	Student students[3] = { {"����̫һ", 100},{"�ǻ�", 14} ,{"ѩŮ", 18} };
	for (int i = 0; i < 3; i++) {
		cout << students[i].name << " " << students[i].age << endl;
	}
	return 0;
}