#include<iostream>
using namespace std;

void print(const int*);

int arr[10];

int main() {
	print(arr);
	return 0;
}

void print(const int ia[10]) {
	for (size_t i = 0; i != 10; ++i) {
		cout << ia[i] << endl;
	}
}
