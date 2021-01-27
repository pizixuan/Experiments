#include<iostream>
#include<string>
#include "Sales_data.h"

void Sales_data::init(std::string bookNo_, int units_sold_, double price_) {
	bookNo = bookNo_;
	units_sold = units_sold_;
	revenue = units_sold * price_;
}

void Sales_data::disp() {
	std::cout << "BookNo is " << bookNo << std::endl;
	std::cout << "units_sold is " << units_sold << std::endl;
	std::cout << "Revenue is " << revenue << std::endl;
}

void Sales_data::add(Sales_data data) {
	if (this->bookNo == data.bookNo) {
		unsigned totalCnt = this->units_sold + data.units_sold;
		double totalRevenue = this->revenue + data.revenue;
		if (totalCnt != 0) {
			std::cout << "This average price is ";
			std::cout << totalRevenue / totalCnt << std::endl;
		}
		else
			std::cout << "No Sales!" << std::endl;
		return;
	}
	else {
		std::cerr << "Data must refer to the same IBSN!" << std::endl;
		return;
	}
	return;
}