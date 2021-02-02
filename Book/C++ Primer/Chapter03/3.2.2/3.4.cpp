#include<iostream>
#include<string>
using namespace std;
int main(){
	cout << "Please enter two string:" << endl;
	string str1, str2;
	cin >> str1 >> str2;	
	cout << (str1 > str2 ? str1 : str2) << endl;
	cout << (str1.size() > str2.size() ? str1 : str2) << endl;
	return 0;
}
