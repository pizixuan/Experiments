#include <iostream>
#include <string>
using namespace std;
class Student {
  public:
    Student() {}
    Student(string s) {}
    Student(istream &is) {} 
  private:
    string bookNo;
};

int main() {
    system("Pause");
    return 0;
}

//如果都使用默认实参会导致编译器不知道该选择哪个构造函数