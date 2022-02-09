#include <iostream>
#include <vector>
using namespace std;

/*
	1、vector基本概念：
		功能：vector数据结构和数组非常相似，也称为单端数组
	2、vector与普通数组区别：
		不同之处在于数组是静态空间，而vector可以动态扩展
	3、动态扩展：
		并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间

	 ❀vector容器的迭代器是支持随机访问的迭代器
	
	4、vector构造函数
		vector<T>						//采用模板实现类实现，默认构造函数 
		vector(v.begin()，v.end());		//将v[begin(), end())区间中的元素拷贝给本身
		vector(n, elem);				//构造函数将n个elem拷贝给本身
		vector(const vector& vec);		//拷贝构造函数

	5、赋值操作
		vector& operator = (const vector& vec);		//重载等号操作符
		assign(beg, end);							//将[beg, end)区间中的数据拷贝赋值给本身
		assign(n, elem);							//将n个elem拷贝赋值给本身

	6、vector容量和大小
		empty();					//判断容器是否为空 
		capacity();					//容器的容量 
		size();						//返回容器中元素的个数 
		resize(int num);			//重新指定容器的长度为num，若容器变长，则以默认值0填充新位置，如果容器变短，则末尾超出容器长度的元素被删除
		resize(int num, elem);		//重新指定容器的长度为num，若容器变长，则以elem值填充新位置，如果容器变短，则末尾超出容器长度的元素被删除

	7、vector插入删除
		push_back(ele);										//尾部插入元素ele 
		pop_back();											//删除最后一个元素 
		insert(const iterator pos, ele);					//迭代器指向位置pos插入元素ele 
		insert(const iterator pos, int count, ele);			//选代器指向位置pos插入count个元素ele
		erase(const iterator pos);							//删除选代器指向的元素 
		erase(const iterator start, const iterator end):	//删除选代器从start到end之间的元素
		clear();											//删除容器中所有元素

	8、vector数据存储
		at(int idx);	//返回索引idx所指的数据 
		operator[];		//返回索引idx所指的数据 
		front();		//返回容器中第一个数据元素 
		back();			//返回容器中最后一个数据元素
	
	9、vector互换容器  实现两容器内元素进行互换
		swap(vec);      //将vec与本身的元素互换

	10、vector预留空间  减少vector在动态扩展容量时的扩展次数
		reserve(int len);  //容器预留len个元素长度，预留位置不初始化，元素不可访问
		

*/

void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//插入删除
void test08() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);   //尾插
	}
	printVector(v);                           //0 1 2 3 4 5 6 7 8 9
	v.pop_back();  //尾删
	printVector(v);							  //0 1 2 3 4 5 6 7 8

	v.insert(v.begin(), 66666);
	printVector(v);                           //66666 0 1 2 3 4 5 6 7 8
	v.insert(v.end(), 6, 8);
	printVector(v);                           //66666 0 1 2 3 4 5 6 7 8 8 8 8 8 8 8

	vector<int>::iterator it = v.begin();
	it++;
	v.erase(it);							  
	printVector(v);							  //66666 1 2 3 4 5 6 7 8 8 8 8 8 8 8

	v.erase(v.begin(), v.end());      //和clear等效
	printVector(v);
}

//构造函数
void test01() {
	vector<int> v1;   //默认构造 无参构造
	for (int i = 0; i < 3; i++) {
		v1.push_back(i + 2);
	}
	printVector(v1);

	//通过区间的方式进行构造
	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

	//n个elem方式构造
	vector<int> v3(5, 8);
	printVector(v3);

	//拷贝构造
	vector<int> v4(v3);
	printVector(v4);
}

//赋值操作
void test02() {
	vector<int> v1;
	for (int i = 0; i < 3; i++) {
		v1.push_back(i + 2);
	}
	printVector(v1);

	//等号赋值
	vector<int> v2 = v1;
	printVector(v2);
	//区间赋值
	vector<int> v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);
	//将n个elem拷贝赋值给本身
	vector<int> v4;
	v4.assign(6, 8);
	printVector(v4);
}

//vector容量和大小
void test03() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	if (!v1.empty()) {
		cout << "容量：" << v1.capacity() << endl;
		cout << "大小：" << v1.size() << endl;
	}

	//重新指定大小
	v1.resize(27);
	printVector(v1);

	v1.resize(6);
	printVector(v1);

	v1.resize(27, 6);
	printVector(v1);

}

//vector数据存储
void test04() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
	cout << v1.at(0) << endl;     //0
	cout << v1[0] << endl;        //0
	cout << v1.front() << endl;	  //0
	cout << v1.back() << endl;    //9

}

//互换容器
void test05() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	vector<int> v2;
	for (int i = 10; i > 0; i--) {
		v2.push_back(i);
	}

	cout << "互换前：" << endl;
	printVector(v1);
	printVector(v2);

	v1.swap(v2);
	cout << "互换后：" << endl;
	printVector(v1);
	printVector(v2);

	/*
		结果：
			互换前：
			0 1 2 3 4 5 6 7 8 9
			10 9 8 7 6 5 4 3 2 1
			互换后：
			10 9 8 7 6 5 4 3 2 1
			0 1 2 3 4 5 6 7 8 9
	*/
}

//互换实际用途
void test06() {
	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	cout << "容量：" << v.capacity() << endl;   //138255
	cout << "大小：" << v.size() << endl;       //100000

	v.resize(3);  //resize改变的只是size的大小，容量并不会变化 导致造成空间的浪费
	cout << "容量：" << v.capacity() << endl;   //138255
	cout << "大小：" << v.size() << endl;		//3

	//❀巧用swap收缩内存
	vector<int>(v).swap(v);    //vector<int>(v):匿名对象    swap指针互换
	printVector(v);
	cout << "容量：" << v.capacity() << endl;   //3
	cout << "大小：" << v.size() << endl;		//3

}

//vector容器 预留空间
void test07() {
	vector<int> v;

	//利用reserve预留空间
	v.reserve(100000);

	int num = 0;  //统计开辟次数
	int* p = NULL;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}
	cout << "10万数据开辟了内存的次数：" << num << endl;  //30次 ,加了v.reserve(100000);后开辟次数：1次
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();
	return 0;
}