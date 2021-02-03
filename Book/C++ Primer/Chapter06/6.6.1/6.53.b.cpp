#include<iostream>
using namespace std;

int calc(char *, char *);
int calc(const char *, const char *);
void func() {
	char num1[5] = {'H','e','l','l','o'};
	char num2[2] = {'m','y'};
	calc(num1, num2);
	const char num3[4] = {'d','e','a','r'};
	const char num4[6] = {'f','r','i','e','n','d'};
	calc(num3, num4);
}

int main() {
	func();
	return 0;
}

int calc(char *i, char *j) {
	*i = 'H';	// 允许 
	cout << "i is " << *i<< " j is " << *j << endl;
	return 0;
}

int calc(const char *i, const char *j) {
//	*i = 'D';	//error pointer to char 试图改变 指针所指的值 
	cout << "i is " << *i << " j is " << *j << endl;
	return 0;
}
