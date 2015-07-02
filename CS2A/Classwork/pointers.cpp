#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main() {
	int j = 10;
	long i = (long) &j;

	cout << "The pointer to the variable to j is " << &j << "\n";
	cout << "i = " << i <<endl;
}
