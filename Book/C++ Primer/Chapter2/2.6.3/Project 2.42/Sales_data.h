#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<iostream>
#include<string>
using namespace std;
class Sales_data {
public:
	string bookNo;
	int units_sold;
	double revenue;
	void init(string bookNo_, int units_sold_, double price_);
	void disp();
};
#endif