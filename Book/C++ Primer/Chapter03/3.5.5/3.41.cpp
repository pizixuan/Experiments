#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main(){
	int nums[] = {0,1,2,3,4};
	vector<int> res(begin(nums), end(nums));
	for (int i : res)
		cout << i << " ";
	
	
	
	return 0;
} 
