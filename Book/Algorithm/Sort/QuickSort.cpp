#include <iostream>
using namespace std;
int a[100], n;

void quickSort(int left, int right) {
    if (left > right)
        return;
    int temp = a[left];     //基准数
    int i = left;
    int j = right;
    while (i < j) {
        while (a[j] >= temp && j > i)
            j--;
        while (a[i] <= temp && i < j)
            i++;
        if (i < j) {   
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    //基准归位
    a[left] = a[i];
    a[i] = temp;

    quickSort(left, i - 1);
    quickSort(i + 1, right);
}

int main() {
    cout << "输入数组大小：" << endl;
    cin >> n;
    cout << "输入要排序的数组：" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quickSort(0, n - 1);
    cout << "排序后的数组：" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
