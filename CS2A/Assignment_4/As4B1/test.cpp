#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main () {
    // define customer variables
    int totalCredits = 0;
    // define program variables
    string userInput, firstChar, indicator;
    int userInputInt;
    // define constants
    const string ERROR_1 = "*** Use P or S, please ***\n";
    const string ERROR_2 = "\n*** Use Y or N, please ***\n\n";
    const string MENU = "Menu: \n \t P (process Purchase) \n \t S (Shut down)\n";
    // Perpetual Loop (Exit with Control C)
    while (indicator != "terminate") {
        indicator = "buy"; // initalize indicator as "buy"
        cout<<MENU; // display menu
        cin>>userInput;
        firstChar = userInput.at(0); // takes first character
        cout << "\nYour Choice: " << firstChar << "\n";
	
    // P Output
        if (firstChar == "s" || firstChar == "S") {
        indicator = "terminate"; //terminates program
    }
	
    // S Logic
        if (totalCredits >= 10) {
            cout<<"\nYou qualify for a free yogurt. Would you like to use your credits? (Y or N) \n\n";
            cin>>userInput;
            if (userInput == "y" || userInput == "Y") {
                totalCredits -= 10; // deducts credit
                cout << "\nYou have just used 10 stamps and have " << totalCredits << " left.\n\n";
                indicator = "free"; // indicates free
            } else if (userInput != "n" && userInput != "N") {
                indicator = "error"; // disqualify users for purchase
            }
        }
        if (indicator == "buy" && (firstChar == "p" || firstChar == "P")) {
            cout << "\nHow many yogurts would you like to buy?: ";
            cin >> userInputInt;
            totalCredits += userInputInt;
            cout << "\nYou just earned " << userInputInt << " stamps ";
            cout << "and have a total of " << totalCredits << "\n\n";
        } else if (indicator == "free") {
            // do nothing
        } else if (indicator == "error") {
            cout<<ERROR_2;
        }
        // Error Output
        else {  // Outputs error and loops continues
            cout<<ERROR_1<<"\n";
        }
    } //while
    return 0;
}
