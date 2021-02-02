#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
	int punctNum = 0;
	string str = "Hello,Wor,ld!";
	for (int i = 0; i < str.size()-punctNum; ++i){
		if ((ispunct(str[i]) && punctNum == 0) || ispunct(str[i+punctNum]))
			punctNum++;
		str[i] = str[i+punctNum];
	}
	for (int i = str.size()-1; i >= str.size()-punctNum; --i)
		str[i] = ' ';
	cout << str << endl;
	return 0;
}
