#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	vector<int> res;
	int i = 0;
	while (i < 10){
		int num;
		cin >> num;
		res.push_back(num);
		i++;
	}
	
	for (auto j : res)
		cout << j << " ";
	return 0;
}
