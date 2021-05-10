#include<bits/stdc++.h>
using namespace std;

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " "; 
    cout << endl;
}

void insertSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1; 
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    //@插入排序
    int arr[10] = {10, 4, 5, 7, 9, 2, 3, 1, 6, 8};
    int len = 10;
    cout << "before:" << endl;
    print_arr(arr, len);
    insertSort(arr, len);            
    cout << "after:" << endl;
    print_arr(arr, len);
    return 0;
}