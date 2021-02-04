#pragma once
#include<iostream>
#include <string>
#ifndef PERSON_H
#define PERSON_H
class Person {
public:
	std::string name;
	std::string adress;

	std::string getName() const;
	void setName(std::string str);
	std::string getAdress() const;
	void setName(std::string str);
};
#endif // !PERSON_H