#include<iostream>
using namespace std;

int fact(int);

int main() {
	int num = 0;
	return 0;
}

int fact(int val) {
	int ret = 1;
	while (val > 1) 
		ret *= val--;
	return ret; 
}
