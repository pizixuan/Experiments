#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> arr = {42, 65, 95, 100, 39, 67, 95, 76, 88, 76, 83, 92, 76, 93};
	vector<int> res(11, 0);
	vector<int>::iterator i = res.begin();
	for (int j : arr){
		int ans = j / 10;
		++*(i + ans);
	}
	for (int j : res)
		cout << j << " ";
	return 0;
}
