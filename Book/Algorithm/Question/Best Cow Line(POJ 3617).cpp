#include<iostream>
#include<string>
using namespace std;
int N;

int main() {
	//ִ������
	cout << "������N�Ĵ�С" << endl;
	cout << "�������ַ���S" << endl;
/*	
	6
	ACDBCB
*/	
	cin >> N;
	char S[N];
	char T[N];
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	int a = 0, b = N-1, index = 0;
	while (a <= b) {
		bool left = true;
		for (int i = 0; i <= b-i; ++i) {
			if (S[a+i] < S[b-i]) {
				left = true;
				break;
			} else if ((S[a+i] > S[b-i])){
			left = false;
			break;
		}
	}
	if (left)
			T[index++] = S[a++];
		else
			T[index++] = S[b--];
	}
	cout << T << endl;
}
