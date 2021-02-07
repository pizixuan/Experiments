#include <iostream>
using namespace std;

class Y;
class X {
  public:
    Y *p;
    char eleX = 'X';
};

class Y {
  public:
    X q;
    char eleY = 'X';
};

int main() {
    X myX;
    Y myY;
    cout << myY.q.eleX << endl;
    cout << myX.p->eleY << endl;
    system("pause");
    return 0;
}