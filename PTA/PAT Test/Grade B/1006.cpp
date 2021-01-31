#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int num[3] = {0};
    int count = 0;
    while (n != 0) {
        int temp = n % 10;
        num[2-count++] = temp;
        n -= temp;
        n /= 10;        
    }
    for (int i = 0; i < num[0]; ++i)
        cout << "B";
    for (int i = 0; i < num[1]; ++i)
        cout << "S";
    for (int i = 1; i <= num[2]; ++i)
        cout << i;
    return 0;
}
