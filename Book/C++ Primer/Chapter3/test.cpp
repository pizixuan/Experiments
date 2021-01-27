#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
	string str("some string!!!");
	decltype(str.size()) punct_cnt = 0;
	for (auto c : str)
		if (ispunct(c))
			++punct_cnt;
	cout << punct_cnt
		 << " punctuation characters in " << str << endl;
	cout << "=================" << endl;
	for (auto &c : str)
		c = toupper(c);
	cout << str << endl;
}
