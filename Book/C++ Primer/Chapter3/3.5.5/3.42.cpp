#include<iostream>
#include<vector>
#include<iterator>
using namespace std; 
int main(){
	vector<int> a1(10, 1);
	int a2[10];
	vector<int>::iterator l = a1.begin();
	vector<int>::iterator r = a1.end();
	while (l != r){
		a2[l-a1.begin()] = *l;
		l++;
	}
	for (int i : a2)
		cout << i << " ";
	return 0;
}
