#include <iostream>
#include <string>
#include "Person.h"
using namespace std;
int main() {
	Person ironMan;
	ironMan.setName("Stack");
	ironMan.setAdress("USA");
	print(cout, ironMan);
	return 0;
}