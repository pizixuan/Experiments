#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
	string text = "text";
	auto it = text.cbegin();
	//const_iterator 不可改元素
	//iterator 可改元素 
	cout << *it << endl;
}
