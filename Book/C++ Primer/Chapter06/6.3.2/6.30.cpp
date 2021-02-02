#include<iostream>
using namespace std;

bool str_subrange(const string &, const string &);

int main() {
//	str_subrange();
	return 0;
} 

bool str_subrange(const string &str1, const string &str2) {
	if (str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();	//error size 声明无效 
	for (decltype(size) i = 0; i != size; ++i) {							//error	导致 i 没有声明 
		if (str1[i] != str2[i])
			return;
	}
}
