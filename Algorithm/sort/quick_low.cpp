#include <bits/stdc++.h>
using namespace std;

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high + 1;
    while (1) {
        while (arr[++i] < pivot);
        while (arr[--j] > pivot);
        if (i < j)
            swap(arr[i], arr[j]);
        else
            break;
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = partition(arr, low, high);
        quickSort(arr, low, mid - 1);
        quickSort(arr, mid + 1, high);
    }
}

int main() {
    //@快速排序
    int arr[10] = {10, 4, 5, 7, 9, 2, 3, 1, 6, 8};
    int len = 10;
    cout << "before:" << endl;
    print_arr(arr, len);
    quickSort(arr, 0, len - 1);            
    cout << "after:" << endl;
    print_arr(arr, len);
    return 0;
}