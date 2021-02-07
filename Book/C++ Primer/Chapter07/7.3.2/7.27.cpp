
#include <iostream>
using namespace std;

class Screen {
  public:
    typedef string::size_type sz;
    Screen() = default;
    Screen(sz ht, sz wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(sz ht, sz wd, char c)
        : height(ht), width(wd), contents(ht * wd, c) {}
    char getCursorContents() { return contents[cursor]; }
    Screen &move(sz r, sz c);
    Screen &set(char c);
    Screen &set(sz r, sz col, char c);
    Screen &display(ostream &os) {
        do_display(os);
        return *this;
    }
    const Screen &display(ostream &os) const {
        do_display(os);
        return *this;
    }

  private:
    sz cursor = 0;
    sz height = 0, width = 0;
    std::string contents;
    void do_display(ostream &os) const { os << contents << endl; }
};

inline Screen &Screen::move(sz r, sz c) {
    sz row = r * width;
    cursor = row + c;
    return *this;
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}
inline Screen &Screen::set(sz r, sz col, char c) {
    contents[r * width, col] = c;    
    return *this; 
}

int main() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
    system("pause");
    return 0;
}