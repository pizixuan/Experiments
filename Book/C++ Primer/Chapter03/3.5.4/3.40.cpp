#include<iostream>
#include<cstring>
using namespace std;
int main() {
	const char ca1[] = "C plus plus is my";
	const char ca2[] = "favorite programming language";
	char ca3[strlen(ca1)+strlen(ca2)+1];
	strcpy(ca3, ca1);
	strcat(ca3, " ");
	strcat(ca3, ca2);
	for (char i : ca3)
		cout << i;
	return 0;
}
