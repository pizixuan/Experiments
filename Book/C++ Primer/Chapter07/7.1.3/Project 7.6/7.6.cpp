#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;
int main() {
	Sales_data total, trans;
	while (1) {
		cout << "Please enter bookNo, units_sold, price" << endl;
		read(cin, total);
		read(cin, trans);
		if (total.isbn() == trans.isbn()) {
			print(cout, add(total, trans));
			break;
		}
		else {
			cout << "Error! No Data! Please enter again" << endl;
		}
	}
}