#include<iostream>
#include<iterator>
using namespace std;
int main() {
	int arr[10] = {1};
	int count = 0;
	for (int &i : arr)
		i = count++;
	for (int i : arr)
		cout << i << " ";
	cout << endl;
	cout << "=======================" << endl;
	int *beg = begin(arr);
	int *last = end(arr);
	while (beg != last)
		*(beg++) = 0;
	for (int i : arr)
		cout << i << " ";
	return 0;
}
