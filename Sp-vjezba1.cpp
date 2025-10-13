
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
/*
int main()
{
	bool flag;
	std::cout << "unesi " << true << " - " << false << std::endl;
	std::cin >> flag;
	std::cout << std::boolalpha << flag << std::endl;
	int a = 255;
	std::cout << "hex " << std::hex << a << std::endl;
	std::cout << "dec " << std::dec << a << std::endl;
	std::cout << "oct " << std::oct << a << std::endl;
	double pi = 3.141592;
	std::cout << "pi = " << std::scientific << std::uppercase;
	std::cout << std::setprecision(7) << std::setw(20);
	std::cout << std::setfill('0');
	std::cout << pi << std::endl;
	int broj = 42;}int fun(int value, int low = 0, int high = 100) {	if (value < low) return low;	if (value > high) return high;	return value;}double fun(double value, double low = 0.0, double high = 1.0) {	if (value < low) return low;	if (value > high) return high;	return value;}int main() {	std::cout << fun(5, 10, 20) << std::endl;	std::cout << fun(-0.5) << std::endl;}int main() {	std::string s;	std::cout << "unesi cijeli red teksta: ";	std::getline(std::cin, s);	for (char& c : s) {		if (std::isalpha(static_cast<unsigned char>(c))) {			c = std::toupper(static_cast<unsigned char>(c));		}		else if (std::isdigit(static_cast<unsigned char>(c))) {			c = '*';		}		else if (c == ' ' || c == '\t') {			c = '_';		}	}	std::cout << "izmjenjen string" << s << std::endl;	return 0;}*/