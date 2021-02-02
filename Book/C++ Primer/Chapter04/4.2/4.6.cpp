#include<iostream>
using namespace std;
int main(){
	int num = 0;
	cout << "Please enter a number" << endl;
	cin >> num;
	cout << (num % 2 == 0 ? "even number" : "odd number") << endl;
	return 0;
}
