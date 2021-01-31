#include <iostream>
#include<string>
using namespace std;
int main() {
	int max = -1, min = 101,score;
	int n;
	cin >> n;
	string name, num;
	string maxname, maxnum, minname, minnum;
	for (int i = 0; i < n; i++) {
		cin >> name >> num >> score;
		if (score > max) {
			max = score;
			maxname = name;
			maxnum = num;
		}
		if (score < min) {
			min = score;
			minname = name;
			minnum = num;
		}
	}
	cout << maxname << " " << maxnum << endl;
	cout << minname << " " << minnum << endl;
	return 0;
}

