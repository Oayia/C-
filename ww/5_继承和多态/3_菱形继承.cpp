#include <iostream>
using namespace std;

/* 菱形继承：
*	两个派生类继承自同一个基类，又有某一类同时继承这两个派生类，这种继承被称为菱形继承，也叫钻石继承
   
   利用虚拟继承可解决菱形继承的问题，继承之前加关键字virtual，变为虚继承
   Animal类称为 虚基类

   加virtual前Alpaca对象模型：
		3 菱形继承.cpp
		class Alpaca    size(8):
				+---
		 0      | +--- (base class Sheep)
		 0      | | +--- (base class Animal)
		 0      | | | age
				| | +---
				| +---
		 4      | +--- (base class Camel)
		 4      | | +--- (base class Animal)
		 4      | | | age
				| | +---
				| +---
				+---
     加virtual后Alpaca对象模型：
		3 菱形继承.cpp
		class Alpaca    size(12):
				+---
		 0      | +--- (base class Sheep)
		 0      | | {vbptr}                         🌼    //vbptr虚基类指针，指向一个vbtable虚基类表(v:vitual b:base ptr:point)
				| +---
		 4      | +--- (base class Camel)
		 4      | | {vbptr}          ▼
				| +---
				+---
				+--- (virtual base Animal)
		 8      | age                            🎈
				+---

		Alpaca::$vbtable@Sheep@:
		 0      | 0
		 1      | 8 (Alpacad(Sheep+0)Animal)   //这个偏移量是8，即🌼所在行的0加上8之后，对应的是🎈所在行

		Alpaca::$vbtable@Camel@:
		 0      | 0
		 1      | 4 (Alpacad(Camel+0)Animal)    //这个偏移量是4，即▼所在行的4加上4之后，对应的也是🎈所在行
		vbi:       class  offset o.vbptr  o.vbte fVtorDisp
				  Animal       8       0       4 0
*/

//动物类
class Animal {
public:
	int age;
};

//羊类
class Sheep : virtual public Animal {

};

//驼类
class Camel : virtual public Animal {

};

//羊驼
class Alpaca :public Sheep, public Camel {

};

void test01() {
	Alpaca a;
	//虚继承后最终值取决于先后赋值顺序，因为只有一份数据
	a.Camel::age = 3;
	a.Sheep::age = 2;
	//a.age = 1;  //因为🐏这边有一份，🐫这边也有一份，编译器不知道怎么搞
	//当出现菱形继承时，两父类拥有相同的数据，加作用域即可解决，但访问age却是不同的值，这是有问题的，那么怎么解决的呢，让这两父类虚继承虚基类Animal
	cout << a.Sheep::age << endl;
	cout << a.Camel::age << endl;

	//虚继承后，直接访问age即可，因为底层只有一份 
	cout << a.age << endl;
}

int main() {
	test01();
	return 0;
}