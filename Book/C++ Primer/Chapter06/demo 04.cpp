#include<iostream>
#include<string>
using namespace std;
typedef string::size_type sz;

sz ht = 10;
sz wd = 10;
char def = '*';

string screen(sz = ht, sz = wd, char = def);
string screen2(sz = 20, sz = 20, char = '*');	// �Ѷ���Ĭ��ʵ�Σ�ʵ��ʱ���ܸ���Ĭ��ֵ 

string screen3(sz, sz, char = '*');
string screen3(sz = 30, sz = 30, char);	 	// ����Ĭ��ʵ�� 

string window = screen();
string window2 = screen2();

void f() {
	cout << "f: ";	
	def = '1';	// �ı�ȫ�ֱ����Ըı�Ĭ��ʵ��
	sz wd = 100;
//	window = screen();
}

int main() {
	f();
	screen();
	screen2();
	screen2(1,2,'2');	// ��Ȼ��ͨ�����ú������¸���ʵ�� 
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
