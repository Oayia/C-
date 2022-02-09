#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*·文件操作：
		程序运行产生的数据都属于临时数据，程序一旦运行结束都会被释放，通过文件可以将数据持久化
		C++中对文件操作需要包含【头文件<fstream>】

  ·文件类型分为两种：
		文本文件：以ASCII码形式存储在计算机中
		二进制文件：以文本的二进制形式存储在计算器中，用户一般不能直接读懂

  ·操作文件的三大类：
		ofstream：写操作，输出到文件（cout输出到屏幕）
		ifstream：读操作，读到内存（cin读到内存赋值给某变量）
		fstream：读写操作

  ·文件打开方式：
	   打开方式		         解释
		ios:in			为读文件而打开文件
		ios:out			为写文件而打开文件
		ios:ate			初始位置：文件尾
		ios:app			追加方式写文件
		ios:trunc		如果文件存在先删除再创建
		ios:binary		二进制方式
	 注意：文件打开方式可以配合使用，利用|操作符（利用二进制方式写文件：ios:binary|ios:out）
*/

//文本文件 写文件
void test1() {
	ofstream ofs;
	ofs.open("test1.txt", ios::out);
	ofs << "福多多小朋友" << endl;
	ofs << "和花和叶小朋友" << endl;
	ofs.close();
}

//文本文件 读文件
void test2() {
	ifstream ifs;
	ifs.open("test1.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败！" << endl;
		return;
	}
	//读数据
	//方式一
	//char buf[1024] = { 0 };
	//while (ifs >> buf) { //一行一行读，读到buf中去
	//	cout << buf << endl;
	//}
	//ifs.close();

	//方式二
	/*char buf1[1024] = { 0 };
	while (ifs.getline(buf1, sizeof(buf1))) {
		cout << buf1 << endl;
	}*/

	//方式三
	string buf2;
	while (getline(ifs, buf2)) {
		cout << buf2 << endl;
	}

	//方式四，一个字符一个字符的读，不建议使用
	//char c;
	//while ((c = ifs.get()) != EOF) { //EOF end of file
	//	cout << c;
	//}
}

int main() {
	//test1();
	test2();
	return 0;
}