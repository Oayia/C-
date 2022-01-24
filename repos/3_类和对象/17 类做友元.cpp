#include <iostream>
using namespace std;

//类做友元
class Building;
class GoodGirl {
public:
	GoodGirl();
	void visit(); //参观函数 访问Building中的属性

public:
	Building* building;
};

class Building {
	friend class GoodGirl;     //GoodGirl是本类的友元类
public:
	Building();

public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

//类外写成员函数
Building::Building() {
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
GoodGirl::GoodGirl() {
	//创建建筑物对象
	building = new Building;  //★new 堆区创建对象，new什么样的数据类型就返回什么数据类型的指针
}
void GoodGirl::visit() {   //★只需在函数名前添加
	cout << "好基友类正在访问：" << building->m_SittingRoom << endl;
	cout << "好基友类正在访问：" << building->m_BedRoom << endl;
}

void test01() {
	GoodGirl g;
	g.visit();
}
int main() {
	test01();
	return 0;

}