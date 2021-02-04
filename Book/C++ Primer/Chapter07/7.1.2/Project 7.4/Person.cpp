#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

string Person::getName() const {
	return this->name;
}
void Person::setName(std::string str) {
	this->name = str;
}
string Person::getAdress() const {
	return this->adress;
}
void Person::setName(std::string str) {
	this->adress = str;
}