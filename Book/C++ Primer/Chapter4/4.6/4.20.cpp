#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<string> v = {"Hello", "my", "dear", "friend"};
	auto iter = v.begin();
	cout << "*iter++ is " << *iter++ << endl;
//	cout << "(*iter)++ is " << (*iter)++ << endl; //error
//	cout << "*iter.empty() is " << *iter.empty() << endl; //error
	cout << "iter->empty() is " << iter->empty() << endl;
//	cout << "++*iter is " << ++*iter << endl;	//error
	cout << "iter++->empty() is " << iter++->empty() << endl;
	return 0;
}
