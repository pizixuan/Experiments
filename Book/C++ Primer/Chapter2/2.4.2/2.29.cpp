#include<iostream>
using namespace std;
int main(){
	int i, *const cp = 0;
	int *p1, *const p2 = 0;
	const int ic = 0, &r = ic;
	const int *const p3 = &r;
	const int *p = &r;
	
	i = ic;
	p1 = p3;
	p1 = &ic;
	p3 = &ic;
	p2 = p1;
	ic = *p3;
}
