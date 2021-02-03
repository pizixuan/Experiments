#include<iostream>
using namespace std;

int calc(int&, int&);
int calc(const int&, const int&);
void func() {
	int num1 = 10;
	int num2 = 10;
	cout << calc(num1, num2) << endl;
	const int num3 = 10;
	const int num4 = 10;
	cout << calc(num3, num4) << endl;
}

int main() {
	func();
	return 0;
}

int calc(int &i, int &j) { 
	return i + j;
}

int calc(const int &i, const int &j) {
	return i * j;
}
