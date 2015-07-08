#include <iostream>
#include <cmath> 
using namespace std;

int main () {
	int sum [3] = {0,0,0};
	double eExp = 1;
	int i = 0;
	int n = 1000000;

	// while loop
	while (i <= n) {
		sum[0] += i;
		i++;
	}
	cout << "By while loop: " << sum[0] << "\n";

	// do while loop
	i = 0;
	do {
		sum[1] += i;
		i++;
	} while (i <= n); 
        cout << "By do-while loop: " << sum[1] << "\n";	

	// for loop
	for (i = 0; i <= n; i++) {
		sum[2] += i;
	};
	cout << "By for loop: " << sum[2] << "\n";

	// Verify against M_E
	int num = -10;
	for (i = 0; i < abs(num); i++) {	
		if (num < 0) {
			eExp /= M_E;
		}	
		else if (num > 0) {
			eExp *= M_E;
		}
		else if (eExp == 0) {
			eExp = M_E;
		}
	}
	cout << "e^" << num << " is " << eExp << "\n";
	return 0;	
}
