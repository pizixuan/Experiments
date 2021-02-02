#include<iostream>
#include<vector>
#include<iterator>
#include<cstddef>
using namespace std;

int arr1[10];
int arr2[10];	//³õÊ¼Îª 0

int main() {
	int count = 0;
	for (int &i : arr1)
		i = count++;
	for (int &i : arr2)
		i = --count;
	
	for (int i : arr1)
		cout << i << " ";
	cout << endl;
	cout << "==============" << endl;
	for (int i : arr2)
		cout << i << " ";
	cout << endl;
	cout << "==============" << endl;

	int *beg1 = begin(arr1);
	int *last1 = end(arr1);
	int *beg2 = begin(arr2);
	int *last2 = end(arr2);

	if (last1 - beg1 != last2 - beg2)
		cout << "Different Length" << endl;
	else{
		while (beg1 != last1) {
			if (*beg1 != *beg2) {
				cout << "Different Element" << endl;
				break;
			}
			beg1++;
			beg2++;
			if (beg1 == last1)
				cout << "Same" << endl;
		}
	}
	
	cout << "==============" << endl;
	vector<int> v1(10);
	vector<int> v2(10);
	vector<int>::iterator iter_begin_1 = v1.begin();
	vector<int>::iterator iter_end_1 = v1.end();
	vector<int>::iterator iter_begin_2 = v2.begin();
	vector<int>::iterator iter_end_2 = v2.end();
	for (int &i : v1)
		i = count++; 
	for (int &i : v2)
		i = --count;
		
	for (int i : v1)
		cout << i << " ";
	cout << endl;
	cout << "==============" << endl;
	
	for (int i : v2)
		cout << i << " ";
	cout << endl;
	cout << "==============" << endl;
		
	if (iter_end_1 - iter_begin_1 != iter_end_2 - iter_begin_2)
		cout << "Different Length" << endl;
	else{
		while (iter_begin_1 != iter_end_1){
			if (*iter_begin_1 != *iter_begin_2){
				cout << "Different Element" << endl;
				break;
			}
			iter_begin_1++;
			iter_begin_2++;
			if (iter_begin_1 == iter_end_1)
				cout << "Same" << endl;
		}
	}
	
	return 0;
}
