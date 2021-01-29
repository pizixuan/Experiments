#include<iostream>
#include<string>
#include<cctype>
#include<vector>
using namespace std;
int main(){
	vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
	for (auto it = arr.begin(); it < arr.end(); ++it)
		*it *= 2;
	for (auto i : arr)
		cout << i << " ";
	return 0;
}
