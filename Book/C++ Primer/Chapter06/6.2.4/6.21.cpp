#include<iostream>
using namespace std;

int bigNum(int, int *);

int main() {
	int num1 = 1, num2 = 2;
	int *q = &num2;
	cout << bigNum(num1, q) << endl;
	return 0;
}

int bigNum(int i, int *p) {
	return (i > *p) ? i : *p;
}
