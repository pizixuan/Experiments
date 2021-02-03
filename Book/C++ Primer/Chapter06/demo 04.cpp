#include<iostream>
#include<string>
using namespace std;
typedef string::size_type sz;

sz ht = 10;
sz wd = 10;
char def = '*';

string screen(sz = ht, sz = wd, char = def);
string screen2(sz = 20, sz = 20, char = '*');	// 已定义默认实参，实现时不能赋予默认值 

string screen3(sz, sz, char = '*');
string screen3(sz = 30, sz = 30, char);	 	// 赋予默认实参 

string window = screen();
string window2 = screen2();

void f() {
	cout << "f: ";	
	def = '1';	// 改变全局变量以改变默认实参
	sz wd = 100;
//	window = screen();
}

int main() {
	f();
	screen();
	screen2();
	screen2(1,2,'2');	// 仍然可通过调用函数重新赋予实参 
	screen3();
	return 0;
}

string screen(sz ht, sz wd, char def) {
	cout << "screen: " << endl;
	cout << "ht is " << ht << endl;
	cout << "wd is " << wd << endl;
	cout << "def is " << def << endl;
	cout << endl;
	return "";
}

string screen2(sz ht_, sz wd_, char def_) {	// error   sz ht_ = 100
	cout << "screen2:" << endl;
	cout << "ht is " << ht_ << endl;
	cout << "wd is " << wd_ << endl;
	cout << "def is " << def_ << endl;
	cout << endl;
	return "";
}

string screen3(sz ht__, sz wd__, char def__) {
	cout << "screen3:" << endl;
	cout << "ht is " << ht__ << endl;
	cout << "wd is " << wd__ << endl;
	cout << "def is " << def__ << endl;
	cout << endl;
	return "";
}
