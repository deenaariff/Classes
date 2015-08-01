#include <iostream>
#include <time.h>
using namespace std;

double factorialRecursion (double n) {
	if (n < 1.0)
		return 1.0;
	else
		return n*factorialRecursion(n-1.0);
}

double factorialIterative (double n) {
	for (int i = n-1; i != 1.0; i--) {
		n *= i;
	}
	return n;
}

int main () {
	int num1, num2;
	long ts = time(NULL);
	long final;

	// Determine Iterative Time

	for (int k = 0; k < 10000; k++) {
		 factorialIterative(50);
	}
	final = time(NULL) - ts;
	cout << "time: " << final << endl;

	// Determine Recursive Time

	ts = time(NULL);
	for (int k = 0; k < 10000; k++) {
		factorialRecursion(50);
	}
	final = time(NULL) - ts;
	
	cout << "time: " << final << endl;

	 
	return 0;
}
