#include<iostream> 
#include<string>
#include<vector>
using namespace std;

int main(){
	vector<vector<int>> ivec;
//	vector<string> svec = ivec;	//error
	vector<string> svec(10, "null");
	return 0;
}