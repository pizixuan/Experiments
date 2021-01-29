#include<iostream>
#include<string>
using namespace std;
int main(){
	string str1, str2;
	while (cin >> str1){
		str2 += str1;
		if (str2.size() > 10)
			break;
	}
	cout << str2 << endl;
	return 0;
}
