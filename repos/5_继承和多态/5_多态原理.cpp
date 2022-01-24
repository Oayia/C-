#include <iostream>
using namespace std;


class Animal {
public:
	virtual void speak() { 
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal {
public:
	void speak() {
		cout << "喵喵喵~" << endl;
	}
};

class Dog :public Animal {
public:
	void speak() {
		cout << "汪汪汪~" << endl;
	}
};

void doSpeak(Animal& a) {
	a.speak();
}

void test01() {
	/*去掉virtual关键字，Animal类型大小是1字节，加上是4字节，是多了一个虚函数指针vbptr，指向的是一个虚函数表vftable，表内部记录Animal::speak函数地址
	* 
	  ★Animal加了virtual关键字后的对象模型：
		5_多态原理.cpp

			class Animal    size(4) :
			+-- -
			0 | {vfptr}           //指针
		+ -- -

			Animal::$vftable@ :     //表
			| &Animal_meta
			| 0
			0 | &Animal::speak    //记录的是函数地址

			Animal::speak this adjustor : 0
		
	  ★把Cat中的speak重写注释，然后查看Cat的对象模型：
	    5_多态原理.cpp
			class _s__CatchableType size(28):
					+---
			 0      | properties
			 4      | pType
			 8      | _PMD thisDisplacement
			20      | sizeOrOffset
			24      | copyFunction
					+---

			class _s__CatchableTypeArray    size(4):
					+---
			 0      | nCatchableTypes
			 4      | arrayOfCatchableTypes
					+---

			class Cat       size(4):
					+---
			 0      | +--- (base class Animal)
			 0      | | {vfptr}
					| +---
					+---

			Cat::$vftable@:
					| &Cat_meta
					|  0
			 0      | &Animal::speak         //没有重写时继承的还是Animal的speak

		★Cat中speak注释去掉，即对Animal中的speak进行重写，查看Cat对象模型：
		   5_多态原理.cpp
			class _s__CatchableType size(28):
					+---
			 0      | properties
			 4      | pType
			 8      | _PMD thisDisplacement
			20      | sizeOrOffset
			24      | copyFunction
					+---

			class _s__CatchableTypeArray    size(4):
					+---
			 0      | nCatchableTypes
			 4      | arrayOfCatchableTypes
					+---

			class Cat       size(4):
					+---
			 0      | +--- (base class Animal)
			 0      | | {vfptr}
					| +---
					+---

			Cat::$vftable@:
					| &Cat_meta
					|  0
			 0      | &Cat::speak                    //指针指向的已经是Cat，而不是Animal了

			Cat::speak this adjustor: 0

		*/
	cout << sizeof(Animal) << endl;  
}

int main() {
	test01();
	return 0;
}