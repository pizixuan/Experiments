#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;

int main() {
	vector<int> arr1 {42,42,42,42,42};
	vector<int> arr2(5, 42);
	vector<int> arr3(5);
	for (auto &i : arr3)
		i = 42;
	for (int i : arr1)
		cout << i << " ";
	cout << endl;
	cout << "================" << endl;
	for (int i : arr2)
		cout << i << " ";
	cout << endl;
	cout << "================" << endl;
	for (int i : arr3)
		cout << i << " ";
	cout << endl;
	cout << "================" << endl;
}
