#pragma once
#include<iostream>
#include<string>
using namespace std;

#ifndef SALES_DATA_H
#define SALES_DATA_H

class Sales_data {

public:
	string bookNo;
	int units_sold = 0;
	int revenue = 0;

	string isbn() const;
	Sales_data& combine(const Sales_data&);
	double avg_price() const;

};

Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream& read(istream&, Sales_data&);

#endif // !SALES_DATA_H