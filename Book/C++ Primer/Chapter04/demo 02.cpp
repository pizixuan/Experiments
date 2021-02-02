#include<iostream>
#include<stdexcept>
using namespace std;
int main() {
	int i = 0, j = 1;
	try {
		if (i == j)
			throw runtime_error("i == j");
		else if (i < j)
			throw range_error("i < j");
	} catch (runtime_error err) {
		cout << err.what() << endl;
	} catch (range_error err) {
		cout << err.what() << endl;
	}
		return 0;
}
