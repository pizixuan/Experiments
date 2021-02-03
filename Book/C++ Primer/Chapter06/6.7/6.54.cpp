#include<iostream>
#include<vector>
#include<string>
using namespace std;

int func(const int&, const int&);
typedef int (*FP1)(const int&, const int&);	//�� FP1 ���� int(*)(const int&, const int&) 
auto FP2(int) -> int(*)(const int&, const int&);	// ����һ��ָ�����,�ڴ˴������� 

int main() {
	
	int (*fp)(const int&, const int&);
	fp = func;
	cout << fp(1,2) << endl;
	
	FP1 f = func;
	cout << f(1,2) << endl;
	vector<FP1> v(1);
	v[0] = func;
	cout << v[0](1,2) << endl;
	
	vector<decltype(fp)> v2(1); 	// decltype(����) �õ��������� 
	v2[0] = func;
	cout << v2[0](1,2) << endl;
	
	
	return 0;
}

int func(const int &i, const int &j) {
	cout << "i + j is "; 
	return i + j;
}
