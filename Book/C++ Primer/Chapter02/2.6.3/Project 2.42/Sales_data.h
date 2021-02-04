#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<iostream>
#include<string>

class Sales_data {
public:
	std::string bookNo;
	int units_sold;
	double revenue;
	void init(std::string bookNo_, int units_sold_, double price_);
	void disp();
	void add(Sales_data data);
};
#endif
