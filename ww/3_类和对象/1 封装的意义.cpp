#include <iostream>
using namespace std;

const double PI = 3.14;

class Circle {
public:
	int m_r;
	double calculateZC() {
		return 2 * PI * m_r;
	}
};

int main1() {
	Circle c = Circle();
	c.m_r = 10;
	cout << c.calculateZC() << endl;
	return 0;
}