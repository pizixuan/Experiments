#include<iostream>
using namespace std;
int main() {
	int q[102] = { 6,3,1,7,5,8,9,2,4 };
	int head = 0;
	int tail = 9;
	while (head < tail) {
		cout << q[head] << " ";
		head++;

		q[tail] = q[head];
		tail++;
		head++;
	}	
	return 0;
}
