#include<iostream>
#include<vector>
using namespace std;
int main() {

	int count = 0;
	int arr[10] = {0};
	for (int &i : arr) {
		i = count;
		count++;
	}

	cout << "arr is " << endl;
	for (int i : arr)
		cout << i << " ";
	cout << endl;
	cout << "=========================" << endl;
	int arr2[10] = {0};
	count = 0;
	cout << "arr2 is " << endl;
	for(int &i : arr2) {
		i = arr[count++];
		cout << i << " ";
	}
	cout << endl;
	cout << "=========================" << endl;

	vector<int> res(1);
	count = 1;
	while (count < 10)
		res.push_back(count++);
	cout << "res is " << endl;
	for (int i : res)
		cout << i << " ";
	cout << endl;
	cout << "=========================" << endl;

	count = 0;
	vector<int> res2(10);
	for (int &i : res2)
		i = res[count++];
	cout << "res2 is " << endl;
	for (int i : res2)
		cout << i << " ";
	cout << endl;
	cout << "=========================" << endl;
	return 0;
}
