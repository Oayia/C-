#include <iostream>
using namespace std;


class Animal {
public:
	virtual void speak() { 
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal {
public:
	void speak() {
		cout << "������~" << endl;
	}
};

class Dog :public Animal {
public:
	void speak() {
		cout << "������~" << endl;
	}
};

void doSpeak(Animal& a) {
	a.speak();
}

void test01() {
	/*ȥ��virtual�ؼ��֣�Animal���ʹ�С��1�ֽڣ�������4�ֽڣ��Ƕ���һ���麯��ָ��vbptr��ָ�����һ���麯����vftable�����ڲ���¼Animal::speak������ַ
	* 
	  ��Animal����virtual�ؼ��ֺ�Ķ���ģ�ͣ�
		5_��̬ԭ��.cpp

			class Animal    size(4) :
			+-- -
			0 | {vfptr}           //ָ��
		+ -- -

			Animal::$vftable@ :     //��
			| &Animal_meta
			| 0
			0 | &Animal::speak    //��¼���Ǻ�����ַ

			Animal::speak this adjustor : 0
		
	  ���Cat�е�speak��дע�ͣ�Ȼ��鿴Cat�Ķ���ģ�ͣ�
	    5_��̬ԭ��.cpp
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
			 0      | &Animal::speak         //û����дʱ�̳еĻ���Animal��speak

		��Cat��speakע��ȥ��������Animal�е�speak������д���鿴Cat����ģ�ͣ�
		   5_��̬ԭ��.cpp
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
			 0      | &Cat::speak                    //ָ��ָ����Ѿ���Cat��������Animal��

			Cat::speak this adjustor: 0

		*/
	cout << sizeof(Animal) << endl;  
}

int main() {
	test01();
	return 0;
}