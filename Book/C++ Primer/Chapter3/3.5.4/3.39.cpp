#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
	const char ca1[] = "A";
	const char ca2[] = "B";
	cout << (strcmp(ca1, ca2) > 0 ? "ca1 is bigger than ca2" : "ca2 is bigger than ca1") << endl;
	
	string str1 = "A";
	string str2 = "B";
	cout << (str1 > str2 ? "str1 is bigger than str2" : "str2 is bigger than str1") << endl;
	
	return 0;
}
