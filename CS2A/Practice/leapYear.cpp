#include <iostream>
#include <sstream>
using namespace std;

int main () {
	int year; 
	cout << "Enter what year you were born in: ";
	cin >> year;
	int rem = year % 4;
	if (rem == 0) {
		cout << "Yes you were born on a leap year\n";
	}
	else {
		cout << "No you were not born on a leap year\n";
	}
	return 0;
}
