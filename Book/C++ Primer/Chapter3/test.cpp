#include<iostream>
using namespace std;

void quickSortV1(int *, int, int);

int main(){
	int list[10] = {7,8,1,3,4,5,2,6,9,0};
	quickSortV1(list, 0, 9);
	for (auto i : list)
		cout << i << " ";
	return 0;
}

void quickSortV1(int *arr, int l, int r){
	if (l >= r)
		return;
	int x = l, y = r, z = arr[l];
	while (x < y){
		while (x < y && arr[y] >= z)
			--y;
		if (x < y)
			arr[x++] = arr[y];
		while (x < y && arr[x] <= z)
			++x;
		if (x < y)
			arr[y--] = arr[x];
	}
	arr[x] = z;
	quickSortV1(arr, x, y-1);
	quickSortV1(arr, x+1, y);
}