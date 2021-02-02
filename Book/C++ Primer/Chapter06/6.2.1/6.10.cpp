#include<iostream>
using namespace std;

void swap(int*, int*);

int main() {
	int i = 0, j = 1;
	cout << "First: i is " << i << " and j is " << j << endl;
	swap(&i, &j);
	cout << "Second: i is " << i << " and j is " << j << endl;
	return 0;
}

void swap(int *p, int *q) {
	int temp = *p;
	*p = *q;
	*q = temp;
}
