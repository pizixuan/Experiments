#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
	cin >> s;
	int num = 0;
	for (int i = 0; i < s.length(); i++)
		num += (s[i]-'0');
	string res = to_string(num);
    string str[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    for (int i = 0; i < res.length(); i++){
    	if (i != 0)
    		cout << " ";
    	cout << str[res[i] - '0'];
	}
    return 0;
}
