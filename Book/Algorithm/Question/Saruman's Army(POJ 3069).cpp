#include<iostream>
using namespace std;
int main(){
	int N;	//������� 
	int R;	//���� 
	cin >> N;
	cin >> R;
	int X[N];
	for (int i = 0; i < N; ++i){
		cin >> X[i];
	}
/*
	ִ������ 
	6
	10
	1 7 15 20 30 50
*/
	int i = 0, ans = 0;
	while (i < N){
		int s = X[i++];
		while (i < N && X[i] <= s + R)
			i++;
		int p = X[i-1];
		while (i < N && X[i] <= p + R)
			i++;
		ans++;
	}
	cout << ans << endl;
}
