#include<iostream>
#include<vector>
#include<iterator>
#include<cstddef>
using namespace std;
int main(){
	int a[] = {1, 2};
	int *beg = begin(a);
	int *last = end(a);
	constexpr size_t sz = 5;
	cout << sz << endl;
}
