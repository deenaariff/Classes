#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main() {
	int j = 10;
	// long i = (long) &j;
	char *p = (char *) &j;

	cout << "The pointer to the variable to j is " << &j << "\n";
	cout << "j = " << j <<endl;
	cout <<"*p = " << (int) (*p) << endl;

	// What does that tell us about the ENDIAN-NESS of the MAC?

	// Now change the value of j indirectly
	*(p+1) = 1;
	
	// What is j now? Predict and then run to check.
	cout << "j is now " << j << endl;
	return 0;	
}
