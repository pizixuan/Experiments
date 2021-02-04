#include<iostream>
#include<string>
#ifndef SALES_DATA_H 
#define SALES_DATA_H
class Sales_data {
public:
	std::string bookNo;
	int units_sold = 0;
	double revenue = 0;

	Sales_data& combine(const Sales_data&);
	std::string isbn() const;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);

#endif // !1