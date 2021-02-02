#include<iostream>
#include<string>
#include<cctype>
#include<vector>
using namespace std;
int main() {
	vector<string> text{"Hello World"};
	for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
		for (auto &i : *it)
			i = toupper(i);
	cout << text[0];
	return 0;
}
