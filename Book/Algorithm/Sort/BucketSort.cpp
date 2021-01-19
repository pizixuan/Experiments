#include<iostream>

/*
	有5名学生，分数为0-10，根据 水桶排序 将分数由大到小打印输出
*/

int main(void) {
	int b[11] = { 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 };
	int t;
	printf("请输入5个数：\n");
	for (int i = 0; i < 5; i++) {	//输入5名学生的分数
		scanf("%d", &t);
		b[t]++;	//这个分数的学生人数 +1
	}
	for (int i = 10; i >= 0; i--) {
		for (int j = 0; j < b[i]; j++) {
			printf("%d ", i);
		}
	}
	return 0;
}
