#include <iostream>
using namespace std;

/*·友元
*		在生活中，你的客厅（public），卧室（私有），客厅所有来往的客人都可以进去，但你的卧室是私有的，只有自己可以进，但是呢，你也可以允许你的好闺蜜进去。
		在程序里，有些私有属性也想让类外特殊的一些函数或者类进行访问，就需要用到友元。
  ·友元的目的就是让一个函数或者类访问另一个类中私有成员。
  ·关键字：friend
  ·友元三种实现：
		1）全局函数做友元
		2）类做友元
		3）类中成员函数做友元
	
*/

class Building {
	friend void goodFriend(Building* b);  //放在类中即可
public:
	Building() {
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
	string m_SittingRoom; //客厅
private:
	string m_BedRoom;  //卧室
};

//全局函数
void goodFriend(Building* b) {
	cout << "好朋友全局函数正在访问：" << b->m_SittingRoom << endl;  //访问公有属性
	cout << "好朋友全局函数正在访问：" << b->m_BedRoom << endl;    //访问私有属性
}

void test01() {
	Building b;
	goodFriend(&b);
}

int main() {
	test01();
	return 0;
}