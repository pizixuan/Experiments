#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int main(){
	string text = "text";
	auto it = text.cbegin();
	//const_iterator ���ɸ�Ԫ��
	//iterator �ɸ�Ԫ�� 
	cout << *it << endl;
}
