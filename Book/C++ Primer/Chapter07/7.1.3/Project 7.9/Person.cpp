#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

string Person::getName() const {
	return this->name;
}
void Person::setName(const std::string& str) {
	this->name = str;
}
string Person::getAdress() const {
	return this->adress;
}
void Person::setAdress(const std::string& str) {
	this->adress = str;
}

ostream& print(ostream& os, const Person& man) {
	os << "name is " << man.name
		<< " adress is " << man.adress << std::endl;
	return os;
}