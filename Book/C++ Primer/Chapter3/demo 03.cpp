#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> res(10, 0);
	auto left = res.begin();
	auto right = res.end();	//Խ�� 
	cout << "left is " << *left << endl;
	cout << "right is " << *right << endl;
}
