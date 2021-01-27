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