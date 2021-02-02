#include<iostream>
using namespace std;

string (&fun(string (&s)[10]))[10]{
    return s;
}

typedef string (&str_arr)[10];
str_arr fun1(str_arr s){
	return s;
}

auto fun2(string (&s)[10]) -> string (&)[10] {
	return s;
}

string d[10];
decltype(d) &fun3(decltype(d) (&s)) {	// &s ºÍ (&s) µÄ²î±ð 
	return s;
}

int main() {
	return 0;
}
