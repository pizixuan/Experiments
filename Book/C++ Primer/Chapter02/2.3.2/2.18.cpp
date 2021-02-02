#include<iostream>
using namespace std;
int main(){
	int v1 = 10;
	int v2 = 1;
	int *p = &v1;
	p = &v2;
	cout << *p << endl;
	*p = 100;
	cout << v2 << endl;
}