#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	char st[10];
	int top = 0;
	int next;
	cout << "请输入字符串(长度小于10)" << endl;
	cin >> str;
	int len = str.length();
	int mid = len / 2 - 1;
	for (int i = 0; i <= mid; i++)
		st[++top] = str[i];
	if (len % 2 == 0)
		next = mid + 1;
	else
		next = mid + 2;
	for (int i = next; i < len; i++) {
		if (top == 0)
			break;
		if (st[top] != str[i])
			break;
		top--;
	}
	if (top == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
