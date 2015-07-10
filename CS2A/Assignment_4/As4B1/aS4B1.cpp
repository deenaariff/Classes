#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main () {
	// define customer variables
	int totalCredits = 0;
	// define program variables
	string userInput, firstChar, indicator;
	int userInputInt;
	// define constants
	const string ERROR_1 = "*** Use P or S, please ***";
	const string ERROR_2 = "*** Use Y or N, please ***";
	const string MENU = "Menu: \n \t P (process Purchase) \n \t S (Shut down)\n";
	// Perpetual Loop (Exit with Control C)
	while (indicator != "terminate") {
		indicator = "buy"; // initalize indicator as "buy"
		cout<<MENU; // display menu
		cin>>userInput;
		firstChar = userInput.at(0); // takes first character
	
		// P Output
		if (firstChar == "s" || firstChar == "S") {
			indicator = "terminate"; //terminates program 
		}
	
		// S Logic
		if (totalCredits >= 10) {
				cout<<"You qualify for a free yogurt. Would you like to use your credits? (Y or N) \n";
				cin>>userInput;
				if (userInput == "y" || userInput == "Y") {
					totalCredits -= 10; // deducts credit
					indicator = "free"; // indicates free
				}	
				else if (userInput != "n" || userInput != "N") {	
					indicator = "error"; // disqualify users for purchase 
				}
		}	
		if (indicator == "buy" && (firstChar == "p" || firstChar == "P")) { 
			cout << "How many yogurts would you like to buy?: ";	
			cin >> userInputInt;
			totalCredits += userInputInt;
			cout << "You just earned " << userInputInt << " stamps ";
			cout << "and have a total of " << totalCredits << "\n";
		}
		else if (indicator == "free") {
		}
		else if (indicator == "error") {
			cout<<ERROR_2;
		}
		// Error Output
		else {  // Outputs error and loops continues
			cout<<ERROR_1<<"\n";
		}
	}
	return 0;
}
