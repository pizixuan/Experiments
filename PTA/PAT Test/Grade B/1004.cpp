#include<iostream>
#include<string>
using namespace std;

struct student {
	string name;
	string sNo;
	int score;
};

int main() {
	int n;
	cin >> n;
	student stu[n];
	student res[2];
	for (int i = 0; i < n; ++i) {
		cin >> stu[i].name;
		cin >> stu[i].sNo;
		cin >> stu[i].score;
		if (i == 0)
			res[0] = stu[0];
		else if (i == 1) {
			if (res[0].score >= stu[i].score)
				res[1] = stu[i]	;
			else {
				res[1] = res[0];
				res[0] = stu[i];
			}
		} else {
			if (stu[i].score > res[0].score) {
				res[1] = res[0];
				res[0] = stu[i];
			} else if (stu[i].score < res[1].score) {
				res[1] = stu[i];
			}
		}
	}

	for (int i = 0; i < 2; ++i)
		cout << res[i].name << " " << res[i].sNo << endl;
	return 0;
}
