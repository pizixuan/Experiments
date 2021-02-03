#include<iostream>
#include<string>
using namespace std;

string &shorterString(string &s1, string &s2) {
	auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
	return const_cast<string&>(r);
}

int main() {
	string str1 = "Hello";
	string str2 = "Hi";
	cout << shorterString(str1, str2) << endl;	
	return 0;
}
