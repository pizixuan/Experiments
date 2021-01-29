#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;

int main() {
	vector<string> str = {"Hello", "my", "dear", "friend"};

	for (string &i : str) {
		for (char &j : i)
			cout << (char)toupper(j);
		cout << " ";
	}

	return 0;
}
