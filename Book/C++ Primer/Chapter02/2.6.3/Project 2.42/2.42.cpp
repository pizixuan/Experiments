#include<iostream>
#include<string>
#include "Sales_data.h"
using namespace std;
int main() {
	string bookNo;
	int units_sold;
	double price;
	Sales_data data1;
	Sales_data data2;
	cout << "Please enter bookNo, units_sold, single price" << endl;
	cin >> bookNo >> units_sold >> price;
	data1.init(bookNo, units_sold, price);
	cout << "=======================" << endl;
	cout << "Please enter bookNo, units_sold, single price" << endl;
	cin >> bookNo >> units_sold >> price;
	data2.init(bookNo, units_sold, price);
	cout << "=======================" << endl;
	data1.disp();
	cout << "=======================" << endl;
	data2.disp();
	cout << "=======================" << endl;
	data1.add(data2);
	return 0;
}