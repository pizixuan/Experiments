#include<iostream>
#include<string>
using namespace std;

const string &shorterString(const string &s1, const string &s2) {
	return s1.size() <= s2.size() ? s1 : s2;
}

int main() {
	string str1 = "Hello";
	string str2 = "Hi";
	cout << shorterString(str1, str2) << endl;	
	return 0;
}
