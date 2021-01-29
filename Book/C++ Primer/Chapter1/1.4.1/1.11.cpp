#include<iostream>
using namespace std;
int main(){
	int v1, v2;
	cout << "Please enter two numbers" << endl;
	cin >> v1 >> v2;
	int sum = 0;
	int num = v1;
	while (num <= v2){
		sum += num;
		num++;
	}
	cout << "The sum of " << v1 << " and " << v2 << " is " << sum;
}
