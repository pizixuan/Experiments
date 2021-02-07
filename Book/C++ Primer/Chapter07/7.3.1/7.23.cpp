#include <iostream>
using namespace std;

class Screen {
  public:
    typedef string::size_type sz;
    Screen() = default;
    Screen(sz ht, sz wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
  private:
    sz cursor = 0;
    sz height = 0, width = 0;
    std::string contents;
};



int main() {
    
    return 0; 
}