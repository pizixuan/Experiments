#include <iostream>
#include <initializer_list>
using namespace std;

int addAll(initializer_list<int>);

int main() {
    initializer_list<int> arr = {1, 1, 1};
    cout << addAll(arr) << endl;
    return 0;
}

int addAll(initializer_list<int> e) {
    int sum = 0;
    for (auto i : e)
        sum += i;
    return sum;
}
