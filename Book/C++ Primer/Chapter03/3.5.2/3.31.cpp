#include<iostream>
using namespace std;
int main(){
	int count = 0;
	int arr[10] = {0};
	for (int &i : arr){
		i = count;
		count++;
	}
	for (int i : arr)
		cout << i << " ";
}
