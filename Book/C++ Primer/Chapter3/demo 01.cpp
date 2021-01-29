#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
	string s = "hello";
	for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
		*it = toupper(*it);
	cout << s;
}