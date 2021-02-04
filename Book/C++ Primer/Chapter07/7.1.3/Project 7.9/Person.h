#pragma once
#include<iostream>
#include <string>
using namespace std;
#ifndef PERSON_H
#define PERSON_H
class Person {
public:
	std::string name;
	std::string adress;

	std::string getName() const;
	void setName(const std::string& str);
	std::string getAdress() const;
	void setAdress(const std::string& str);
};

ostream& print(ostream&, const Person&);

#endif // !PERSON_H