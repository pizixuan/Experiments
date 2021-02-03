#include<iostream>
#include<vector>
#include<string>
using namespace std;

int add(const int&, const int&);
int substract(const int&, const int&);
int multiply(const int&, const int&);
int divide(const int&, const int&);

typedef int (*FP1)(const int&, const int&);	//ÓÃ FP1 ´úÌæ int(*)(const int&, const int&) 
int num1 = 10, num2 = 20;
int main() {
	
	vector<FP1> v(4);
	v[0] = add;
	v[1] = substract;
	v[2] = multiply;
	v[3] = divide;

	cout << v[0](num1, num2) << endl;
	cout << v[1](num1, num2) << endl;
	cout << v[2](num1, num2) << endl;
	cout << v[3](num1, num2) << endl;
	
	return 0;
}

int add(const int &i, const int &j) {
	cout << "i + j is "; 
	return i + j;
}

int substract(const int &i, const int &j) {
	cout << "i - j is "; 
	return i - j;
}

int multiply(const int &i, const int &j) {
	cout << "i ¡Á j is "; 
	return i * j;
}

int divide(const int &i, const int &j) {
	cout << "i ¡Âj is "; 
	return i / j;
}
