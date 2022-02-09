#include <iostream>
using namespace std;

/* 
	·string中单个字符的查询修改：
		char& operator[](int n);		//通过[]方式取字符
		char& at(int n);				//通过at方式获取字符
	   两种方式均可完成单个字符的查询修改操作
	·string插入和删除
		string& insert(int pos, const char* s);			//插入字符串 
		string& insert(int pos, const string& str);		//插入字符串 
		string& insert(int pos, int n, char c);			//在指定位置插入n个字符C 
		
		string& erase(int pos, int n = npos);			//删除从Pos开始的n个字符
*/

//查询 修改
void test() {
	string s = "hello";
	cout << s << endl;
	//查询
	//通过[]访问单个字符
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;
	//通过at访问单个字符
	for (int i = 0; i < s.size(); i++) {
		cout << s.at(i) << " ";
	}
	cout << endl;

	//修改单个字符
	s[0] = 'u';
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;

	s.at(0) = 'g';
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;
}

//插入 删除
void test1() {
	string s = "hello";
	//插入
	s.insert(1, "yuio");   //hyuioello
	cout << s << endl;    
	s.insert(1, 5, 'j');  //hjjjjjyuioello
	cout << s << endl;
	//删除
	s.erase(1, 5);
	cout << s << endl;

}

int main() {
	//test();
	test1();
	return 0;
}