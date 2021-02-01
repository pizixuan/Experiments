#include<iostream>
using namespace std;
int main() {
	char q = 01110001;
	cout << (q << 6) << endl;	//64
	cout << ~(q << 6) << endl;	//-65
	return 0;
}
