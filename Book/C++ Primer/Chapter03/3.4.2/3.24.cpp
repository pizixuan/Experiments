#include<iostream>
#include<vector>
using namespace std;

int main() {
	int array[10] = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
	int count = 0;
	for (int &i : v) {
		i = array[count];
		++count;
	}
	vector<int>::iterator left = v.begin();
	vector<int>::iterator right = v.end() - 1;
	while (left < right) {
		cout << *left + *right << " ";
		++left;
		--right;
	}
	return 0;
}
