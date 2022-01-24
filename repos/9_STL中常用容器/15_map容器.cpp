#include<iostream>
#include<map>
using namespace std;

/*
	1、map基本概念
		map中所有元素都是pair
		pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
		所有元素都会根据元素的键值自动排序
	
	2、本质
		map/multimap属于关联式容器，底层结构是用二叉树实现【无序插入，也会自动根据key值进行排序】
	
	3、优点
		可以根据key值快速找到value值
	
	4、map和multimap区别：
		map不允许容器中有重复key值元素
		multimap允许容器中有重复key值元素

	5、map构造和赋值
		构造：
			map<T1，T2> mp;			//map默认构造函数: 
			map(const map& mp);		//拷贝构造函数 
		赋值:
			map& operator = (const map& mp);	//重载等号操作符

	6、map大小与交换
		size();			//返回容器中元素的数目 
		empty();		//判断容器是否为空 
		swap(st);		//交换两个集合容器

	7、map插入和删除
		insert(elem);		//在容器中插入元素
		clear();			//清除所有元素 
		erase(pos);			//删除pos迭代器所指的元素，返回下一个元素的迭代器
		erase(beg，end);	//删除区间[beg, end)的所有元素，返回下一个元素的迭代器 
		erase(key);			//删除容器中值为key的元素

	8、map查找与统计
		find(key);		//查找key是否存在，若存在，返回该键的元素的迭代器;若不存在，返回end迭代器; 
		count(key);		//统计key的元素个数

	9、map容器排序操作   ❀对于自定义数据类型，map必须要指定排序规则，同set容器
		map容器默认排序规则：按照key值进行从小到大排序
		利用仿函数可以改变排序规则
*/

void printMap(const map<string, string>& m) {
	for (map<string, string>::const_iterator it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
}

class MyCompare {
public:
	bool operator()(const string& v1, const string& v2) const {
		return v1 > v2;
	}
};

//排序
void test05() {
	map<string, string> m;
	m.insert(make_pair("021501", "福多多"));
	m.insert(make_pair("021503", "肉肉"));
	m.insert(make_pair("021502", "萌兰"));
	m.insert(make_pair("021505", "乔兜兜"));
	m.insert(make_pair("021504", "乔包包"));
	printMap(m);

	//指定内置数据类型 降序
	map<string, string, MyCompare> m1;
	m1.insert(make_pair("021501", "福多多"));
	m1.insert(make_pair("021503", "肉肉"));
	m1.insert(make_pair("021502", "萌兰"));
	m1.insert(make_pair("021505", "乔兜兜"));
	m1.insert(make_pair("021504", "乔包包"));
	for (map<string, string, MyCompare>::iterator it = m1.begin(); it != m1.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

}

//map查找与统计
void test04() {
	map<string, string> m;
	m.insert(make_pair("021501", "福多多"));  //匿名对组
	m.insert(make_pair("021503", "肉肉"));
	m.insert(make_pair("021502", "萌兰"));
	m.insert(make_pair("021505", "乔兜兜"));
	m.insert(make_pair("021504", "乔包包"));
	m.insert(make_pair("021504", "和花"));  //key重复后，并不会覆盖，而是插入失败
	printMap(m);

	//查找
	map<string, string>::const_iterator pos = m.find("021505");
	if (pos != m.end()) {
		cout << "找到了" << endl;
		cout << pos->first << " " << pos->second << endl;
	}
	 
	//统计  map不允许插入重复key元素，所以统计结果不是1就是0 找到1找不到0
	cout << m.count("021505") << endl;
}

//map插入和删除
void test03() {
	map<string, string> m1;
	//插入
	//方式一
	m1.insert(pair<string, string>("021501", "福多多"));  //匿名对组
	//方式二
	m1.insert(make_pair("021503", "肉肉"));
	//方式三
	m1.insert(map<string, string>::value_type("021502", "萌兰"));
	//方式四  虽方便，但不建议使用（）
	m1["021509"] = "成大";
	printMap(m1);

	//❀[]不建议插入，用途：利用key访问value
	//cout << m1["021508"] << endl;   //key不存在时，它就会去添加进去以0215208为key，value为""的一个键值对
	//printMap(m1); 
				/*打印结果：
					021501 福多多
					021502 萌兰
					021503 肉肉
					021509 成大

					021501 福多多
					021502 萌兰
					021503 肉肉
					021508
					021509 成大
				  */

	m1.erase(m1.begin());
	printMap(m1);

	m1.erase("021503");  //根据key删除
	printMap(m1);

	m1.erase(m1.begin(), m1.end());  //clear等效
	printMap(m1);

}

//map大小与交换
void test02() {
	map<string, string> m1;
	m1.insert(pair<string, string>("021501", "福多多"));  //匿名对组
	m1.insert(pair<string, string>("021503", "肉肉"));
	m1.insert(pair<string, string>("021502", "萌兰"));
	m1.insert(pair<string, string>("021505", "乔兜兜"));
	m1.insert(pair<string, string>("021504", "乔包包"));
	if (!m1.empty()) {
		cout << m1.size() << endl;
	}

	map<string, string> m2;
	m2.insert(pair<string, string>("021508", "成大"));

	cout << "swap前：" << endl;
	cout << "m1：" << endl;
	printMap(m1);
	cout << "m2：" << endl;
	printMap(m2);

	m1.swap(m2);

	cout << "swap后：" << endl;
	cout << "m1：" << endl;
	printMap(m1);
	cout << "m2：" << endl;
	printMap(m2);
}

//map构造和赋值
void test01() {
	map<string, string> mp;
	mp.insert(pair<string, string>("021501", "福多多"));  //匿名对组
	mp.insert(pair<string, string>("021503", "肉肉"));
	mp.insert(pair<string, string>("021502", "萌兰"));
	mp.insert(pair<string, string>("021505", "乔兜兜"));
	mp.insert(pair<string, string>("021504", "乔包包"));
	printMap(mp);

	cout << "------------" << endl;

	map<string, string> mp1(mp);
	printMap(mp1);

	cout << "------------" << endl;

	map<string, string> mp2 = mp;
	printMap(mp2);
}

int main() {
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
}