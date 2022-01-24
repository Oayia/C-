#include <iostream>
using namespace std;
/* 多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
   解决方式：
	   将父类中的析构函数改为虚析构或者纯虚析构
   
   虚析构和纯虚析构共性：
       可以解决父类指针释放子类对象
	   都需要有具体的函数实现
   虚析构和纯虚析构区别：
		如果是纯虚析构，该类属于抽象类，无法实例化对象
*/

class Animal {
public:
	Animal() {
		cout << "Animal构造函数" << endl;
	}
	//虚析构 可以解决父类指针释放子类对象不干净的问题
	/*virtual ~Animal() {    
		cout << "Animal析构函数" << endl;
	}*/
	//纯虚析构  需要申明也需要实现
	//有了纯虚析构 之后，这个类也属于抽象类，无法实例化对象
	virtual ~Animal() = 0;
	virtual void speak() = 0;
};

//纯虚析构具体实现
Animal::~Animal() {
	cout << "Animal纯虚析构";
}

class Cat :public Animal {
public:
	Cat(string name) {
		this->name = new string(name);
		cout << "Cat构造函数" << endl;
	}
	~Cat() {
		if (name != NULL) {
			delete name;
			name = NULL;
			cout << "Cat析构函数" << endl;
		}
	}
	void speak() {
		cout << *name << " " << "喵喵喵~" << endl;
	}
	string* name;
};

void test01() {
	Animal* a = new Cat("福多多");
	a->speak();
	delete a;   //父类指针在析构时候，不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏，★解决方式：将父类析构改为虚析构
	/* 执行结果：说明子类堆区数据没有释放，导致内存泄露
		Animal构造函数
		Cat构造函数
		福多多 喵喵喵~
		Animal析构函数
	*/
}

int main() {
	test01();
	return 0;
}