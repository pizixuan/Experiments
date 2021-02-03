#include<iostream>
using namespace std;

int calc(char *, char *);
int calc(char* const, char* const);	// error const pointer to char 不可改变指针地址，导致出现 二义性调用！ 

void func() {
	char num1[5] = {'H','e','l','l','o'};
	char num2[2] = {'m','y'};
	calc(num1, num2);
	char num3[4] = {'d','e','a','r'};
	char num4[6] = {'f','r','i','e','n','d'};
	calc(num3, num4);
}

int main() {
	func();
	return 0;
}

int calc(char *i, char *j) {
	cout << "i is " << *i<< " j is " << *j << endl;
	return 0;
}

int calc(char* const i, char* const j) {
	cout << "i is " << *i << " j is " << *j << endl;
	return 0;
}
