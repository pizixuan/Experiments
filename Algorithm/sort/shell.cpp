
#include<bits/stdc++.h>
using namespace std;

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " "; 
    cout << endl;
}

void shellSort(int arr[], int n) {
    for (int inc = n / 2; inc > 0; inc /= 2) {
        for (int i = inc; i < n; ++i) {
            int j = i;
            int key = arr[i];
            while (j >= inc && key < arr[j - inc]) {
                arr[j] = arr[j - inc];
                j -= inc;
            }
            arr[j] = key;
        }
    }
}

int main() {
    //@希尔排序
    int arr[10] = {10, 4, 5, 7, 9, 2, 3, 1, 6, 8};
    int len = 10;
    cout << "before:" << endl;
    print_arr(arr, len);
    shellSort(arr, len);            
    cout << "after:" << endl;
    print_arr(arr, len);
    return 0;
}