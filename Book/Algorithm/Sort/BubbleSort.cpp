#include<iostream>

/*
	ʹ�� ð������ �������С��������
*/

void swap(int& x, int& y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}
int main() {
	int a[100];
	int n;
	printf("������������Ҫ�������С��\n");
	scanf("%d", &n);
	printf("������������Ҫ���֣�\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
	printf("���������飺\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}