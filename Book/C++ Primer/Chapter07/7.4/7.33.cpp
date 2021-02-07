
#include <iostream>
#include <vector>
using namespace std;

class Window_mgr {
  public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);

  private:
    vector<Screen> screens{Screen{24, 80, ' '}};
};

void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

class Screen {
    friend void Window_mgr::clear(ScreenIndex);

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

inline Screen Screen::move(sz r, sz c) {
    sz row = r * width;
    cursor = row + c;
    return *this;
}

inline Screen Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}
inline Screen Screen::set(sz r, sz col, char c) {
    contents[r * width, col] = c;
    return *this;
}

int main() {

    system("pause");
    return 0;
}