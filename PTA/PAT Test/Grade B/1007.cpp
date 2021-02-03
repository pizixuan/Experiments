#include<iostream>
using namespace std;

bool isPrime(int num) {
	for (int i = 2; i * i <= num; ++i)
		if (num % i == 0)
			return false;
	return true;
} 

int main() {
	int n;
	cin >> n;
	int res = 0;
	for (int i = 4; i <= n; ++i) {
		if (isPrime(i-2) && isPrime(i))
			res++;
	}	
	cout << res << endl;
	return 0;
} 
