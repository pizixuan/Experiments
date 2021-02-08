#include <iostream>
#include <string>
using namespace std;

istream &get(istream &);

int main() {
    get(cin);
    system("pause");
    return 0;
}

istream &get(istream &is) {
    auto old_state = is.rdstate();
    is.clear();
    string word;
    getline(is, word);
    cout << word << endl;
    cin.setstate(old_state);
    return is;
}