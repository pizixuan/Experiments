#include<iostream>
#include<string>
#include "Sales_data.h"
int main() {
	std::string bookNo;
	int units_sold;
	double price;
	Sales_data data1;
	std::cout << "Please enter bookNo, units_sold, single price" << std::endl;
	std::cin >> bookNo >> units_sold >> price;
	data1.init(bookNo, units_sold, price);
	data1.disp();
	return 0;
}