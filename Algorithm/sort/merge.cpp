#include <bits/stdc++.h>
using namespace std;

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void mergeArr(int arr[], int temp_arr[], int left, int mid, int right) {
    //临时数组的初始插入点下标
    int post = left;
    int l_post = left;
    int r_post = mid + 1;
    while (l_post <= mid && r_post <= right) {
        if (arr[l_post] < arr[r_post])
            temp_arr[post++] = arr[l_post++];
        else
            temp_arr[post++] = arr[r_post++];
    }
    while (l_post <= mid)
        temp_arr[post++] = arr[l_post++];
    while (r_post <= right)
        temp_arr[post++] = arr[r_post++];
    while (left <= right) {
        arr[left] = temp_arr[left];
        left++;
    }
}

void sliceArr(int arr[], int temp_arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        sliceArr(arr, temp_arr, left, mid);
        sliceArr(arr, temp_arr, mid + 1, right);
        mergeArr(arr, temp_arr, left, mid, right);
    }
}


void mergeSort(int arr[], int n) {
    int *temp_arr = (int*)malloc(n * sizeof(int));
    if (temp_arr) {
        sliceArr(arr, temp_arr, 0, n - 1);
        free(temp_arr);
    }
    else
        cout << "Error: failed to allocate memory" << endl;
}


int main() {
    //@归并排序
    int arr[10] = {10, 4, 5, 7, 9, 2, 3, 1, 6, 8};
    int len = 10;
    cout << "before:" << endl;
    print_arr(arr, len);
    mergeSort(arr, len);            
    cout << "after:" << endl;
    print_arr(arr, len);
    return 0;
}