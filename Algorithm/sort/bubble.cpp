#include<bits/stdc++.h>
using namespace std;

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " "; 
    cout << endl;
}

//@冒泡排序
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j) 
            if (arr[j] > arr[j+1]) 
                swap(arr[j], arr[j+1]);
}

int main() {
    //@冒泡排序
    int arr[10] = {10, 4, 5, 7, 9, 2, 3, 1, 6, 8};
    int len = 10;
    cout << "before:" << endl;
    print_arr(arr, len);
    bubbleSort(arr, len);            
    cout << "after:" << endl;
    print_arr(arr, len);
    return 0;
}