#include <iostream>
using namespace std;

class Screen {
  public:
    typedef string::size_type sz;
    Screen() = default;
    Screen(sz ht, sz wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(sz ht, sz wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}
    char getCursorContents() {
        return contents[cursor];
    }
  private:
    sz cursor = 0;
    sz height = 0, width = 0;
    std::string contents;
};



int main() {
    Screen screen(10, 10);
    cout << screen.getCursorContents() << endl;
    system("pause");
    return 0; 
}