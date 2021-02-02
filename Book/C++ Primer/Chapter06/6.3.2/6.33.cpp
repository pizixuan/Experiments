#include<iostream>
#include<vector>
using namespace std;

int pri(vector<int> , int );

int main() {
	vector<int> v(10);
	int num = 0;
	for (auto &i : v)
		i = num++;
	num = 0;
	pri(v, num);
	return 0;
}

int pri(vector<int> a, int i) {
	if (i == 10)
		return 0;
	cout << a[i++] << " ";
	return pri(a, i);
}
