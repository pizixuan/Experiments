#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int res = 0;
    while (n != 1){
        if (n % 2 == 0)
            n = n / 2;
        else
            n = (n * 3 + 1) / 2;
        res++;
    }
    cout << res;
    return 0;
}
