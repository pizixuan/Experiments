#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	vector<string> str;
	int i = 0;
	while (i < 5){
		string word;
		getline(cin, word);
		str.push_back(word);
		++i;
	}
	
	for(auto j : str)
		cout << j << "|";
	return 0;
}
