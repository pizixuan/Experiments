
#include <iostream>
#include <vector>
using namespace std;

class Screen {

  public:
    typedef string::size_type sz;
    Screen() = default;
    Screen(sz ht, sz wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(sz ht, sz wd, char c)
        : height(ht), width(wd), contents(ht * wd, c) {}
    char getCursorContents() { return contents[cursor]; }
    Screen move(sz r, sz c);
    Screen set(char c);
    Screen set(sz r, sz col, char c);
    Screen display(ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen display(ostream &os) const {
        do_display(os);
        return *this;
    }
    sz size() const { return height * width; }

  private:
    sz cursor = 0;
    sz height = 0, width = 0;
    std::string contents;
    void do_display(ostream &os) const { os << contents << endl; }
};

int main() {

    system("pause");
    return 0;
}