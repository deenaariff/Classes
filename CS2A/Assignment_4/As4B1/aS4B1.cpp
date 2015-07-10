#include <iostream>
#include <sstream>
using namespace std;

int main () {
	// define customer variables
	int totalCredits = 0;
	// define program variables
	string userInput;
	int userInputInt, indicator;
	// define constants
	const string ERROR_1 = "*** Use P or S, please ***";
	const string ERROR_2 = "*** Use Y or N, please ***";
	const string MENU = "Menu: \n \t P (process Purchase) \n \t S (Shut down)\n";
	// Perpetual Loop (Exit with Control C)
	while (indicator != 2) {
		indicator = 0;
		cout<<MENU; // display menu
		getline(cin,userInput); // take user input
		
		// P Output
		if (&userInput.at(0) == "p" || &userInput.at(0) == "P") {
			return 0; //terminates program 
		}
	
		// S Logic
		if (totalCredits == 10) {
				cout<<"You qualify for a free yogurt. Would you like to use your credits? (Y or N)";
				cin<<userInput;
				if (userInput == "y" || userInput == "Y") {
					totalCredits = 0;				
				}	
				else if (userInput == "n" || userInput == "N") {	
				}
				else {
					indicator = 1;
				}
		}	
		if (&userInput.at(0) == "s" || &userInput.at(0) == "S") { 
			cout << "How many yogurts would you like to buy?: ";	
			getline(cin,userInputInt);
			totalCredits += userInputInt;
			cout << "You just earned " << userInputInt << " stamps ";
			cout << "and have a total of" << totalCredits;
		}
		else if (indicator == 1) {
			cout<<ERROR_2;
		}

		// Error Output
		else {  // Outputs error and loops continues
			cout<<ERROR_1;
		}
	}
	return 0;
}
