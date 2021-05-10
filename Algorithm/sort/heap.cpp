#include <bits/stdc++.h>
using namespace std;

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " "; 
    cout << endl;
}

void heapify (int arr[], int n, int i) {
    if (i >= n)
        return;
    int largest = i;
    int l_son = i * 2 + 1;
    int r_son = i * 2 + 2;

    if (l_son < n && arr[l_son] > arr[largest])
        largest = l_son;
    if (r_son < n && arr[r_son] > arr[largest])
        largest = r_son;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int last = n - 1;
    for (int i = (last - 1) / 2; i >= 0; --i)
        heapify(arr, n, i);
    
    for (int i = n - 1; i >= 0; --i) {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

int main() {
    //@堆排序
    int arr[10] = {10, 4, 5, 7, 9, 2, 3, 1, 6, 8};
    int len = 10;
    cout << "before:" << endl;
    print_arr(arr, len);
    heapSort(arr, len);            
    cout << "after:" << endl;
    print_arr(arr, len);
    return 0;
}