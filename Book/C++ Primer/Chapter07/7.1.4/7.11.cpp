#include<iostream>
#include<string>
using namespace std;
#ifndef SALES_DATA_H 
#define SALES_DATA_H
class Sales_data {
public:
	string bookNo;
	int units_sold = 0;
	double revenue = 0;
	Sales_data() = default;
	Sales_data(const string &s, int n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}	//初始构造函数

	Sales_data(istream& s) {	// istream 作为构造函数参数
		s >> bookNo >> units_sold >> revenue;
	}	

	Sales_data& combine(const Sales_data&);
	string isbn() const;
};

Sales_data add(const Sales_data&, const Sales_data&);
istream& read(istream&, Sales_data&);
ostream& print(ostream&, const Sales_data&);

#endif // !1

int main() {
	Sales_data total("x01", 10, 10.0);	//调用构造函数
	cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
	Sales_data is(cin);
	print(cout, is);
	system("pause");
	return 0;
}


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