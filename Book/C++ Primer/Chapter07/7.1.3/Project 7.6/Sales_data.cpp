#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;

istream& read(istream& is, Sales_data& data) {
	double price;
	is >> data.bookNo >> data.units_sold >> price;
	data.revenue = data.units_sold * price;
	return is;
}

ostream& print(ostream& os, const Sales_data& data) {
	os << "bookNo is " << data.bookNo
		<< " units_sold is " << data.units_sold
		<< " revenue is " << data.revenue << std::endl;
	return os;
}

string Sales_data::isbn() const {
	return this->bookNo;
}

Sales_data add(const Sales_data& data1, const Sales_data& data2) {
	Sales_data sum = data1;
	sum.combine(data2);
	return sum;
}

Sales_data& Sales_data::combine(const Sales_data& data) {
	units_sold += data.units_sold;
	revenue += data.revenue;
	return *this;
}