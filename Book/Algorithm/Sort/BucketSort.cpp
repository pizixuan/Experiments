#include<iostream>

/*
	��5��ѧ��������Ϊ0-10������ ˮͰ���� �������ɴ�С��ӡ���
*/

int main(void) {
	int b[11] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 };
	int t;
	printf("������5������\n");
	for (int i = 0; i < 5; i++) {	//����5��ѧ���ķ���
		scanf("%d", &t);
		b[t]++;	//���������ѧ������ +1
	}
	for (int i = 10; i >= 0; i--) {
		for (int j = 0; j < b[i]; j++) {
			printf("%d ", i);
		}
	}
	return 0;
}
