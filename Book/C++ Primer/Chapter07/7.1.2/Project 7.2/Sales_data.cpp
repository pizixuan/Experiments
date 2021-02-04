#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;

string Sales_data::isbn() const {
	return this->bookNo;
}

Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price() const {
	if (this->units_sold)
		return revenue / units_sold;
	else
		return 0;
}

ostream& print(ostream& os, const Sales_data& data) {
	return 
	os << "bookNo is " << data.bookNo 
	   << " units_sold is " << data.units_sold
	   << " data.revenue is " << data.revenue << std::endl;
}

istream& read(istream& is, Sales_data& data) {
	return is >> data.bookNo >> data.units_sold >> data.revenue;	
}