#include <iostream>
#include <sstream>
using namespace std;

int main (int argc, const char * argv[]) {
	int myChar;
	cout << "Enter a character: ";
	cin >> myChar;
	cout << "The ASCII Value of " << myChar << " is " << int (myChar) << endl;
	return 0;
}
