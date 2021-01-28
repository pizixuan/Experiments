#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {

	vector<int> v1;
	for (auto i : v1)
		cout << i;
	cout << endl;

	cout << "=================" << endl;

	vector<int> v2(10);
	for (auto i : v2)
		cout << i << " ";
	cout << endl;

	cout << "=================" << endl;

	vector<int> v3(10, 42);
	for (auto i : v3)
		cout << i << " ";
	cout << endl;

	cout << "=================" << endl;

	vector<int> v4 {10};
	for (auto i : v4)
		cout << i << " ";
	cout << endl;

	cout << "=================" << endl;

	vector<int> v5 {10, 42};
	for (auto i : v5)
		cout << i << " ";
	cout << endl;

	cout << "=================" << endl;

	vector<string> v6 {10};
	for (auto i : v6)
		cout << i << " ";
	cout << endl;
	
	cout << "=================" << endl;

	vector<string> v7 {10, "hi"};
	for (auto i : v7)
		cout << i << " ";
	cout << endl;
}
