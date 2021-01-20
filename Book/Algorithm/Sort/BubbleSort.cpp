#include<iostream>

/*
	使用 冒泡排序 将数组从小到大排列
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
	printf("请输入你所需要的数组大小：\n");
	scanf("%d", &n);
	printf("请输入你所需要数字：\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
	printf("排序后的数组：\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}