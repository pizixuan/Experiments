#include<iostream>
#include<stdexcept>
#include<exception>
using namespace std;

void test() {
	try {
		cout << "Please Enter two numbers:" << endl;
		int i, j;
		cin >> i >> j;
		if (j == 0)
			throw runtime_error("num2 can't be 0");
		else
			cout << static_cast<double>(i/j);
	} catch (runtime_error err) {
		cout << err.what() << endl << endl;;
		int jud = 0;
		cout << "Enter again  0" << endl << endl;;
		cout << "Give   up    1" << endl << endl;;
		cin >> jud;
		if (jud == 0)
			test();
	}
}

int main() {
	test();
	return 0; 
}
