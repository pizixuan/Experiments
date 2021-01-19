#include <iostream>
using namespace std;
int a[100], n;

void quickSort(int left, int right) {
    if (left > right)
        return;
    int temp = a[left];     //��׼��
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
    //��׼��λ
    a[left] = a[i];
    a[i] = temp;

    quickSort(left, i - 1);
    quickSort(i + 1, right);
}

int main() {
    cout << "���������С��" << endl;
    cin >> n;
    cout << "����Ҫ��������飺" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quickSort(0, n - 1);
    cout << "���������飺" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
