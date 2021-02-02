#include<iostream>
using namespace std;
int main() {
	char q = 01110001;
	cout << (q << 6) << endl;	//64 ²¹Âë = ×ÔÉí 
	cout << ~(q << 6) << endl;	//-65 ²¹Âë = ·ûºÅ£¨·´Âë + 1 £© 
	return 0;
}
