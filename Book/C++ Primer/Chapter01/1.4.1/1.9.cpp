#include<iostream>
using namespace std;
int main(){
	int sum = 0;
	int num = 50;
	while (num <= 100){
		sum += num;
		num++;
	}
	cout << "The sum of 50-100 is " << sum << endl;
} 
