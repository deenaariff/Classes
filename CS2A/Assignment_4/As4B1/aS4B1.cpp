//
Assignment: 4A
// Author: Deen Aariff
// Foothill ID: 20208433
// Creation Date: 07/09/15
// Description: Yogurt Rewards Program

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
    const string ERROR_1 = "\n*** Use P or S, please ***\n";
    const string ERROR_2 = "\n*** Use Y or N, please ***\n\n";
    const string ERROR_3 = "\n*** Value Must be in Range (0-50) ***\n\n";
    const string MENU = "Menu: \n\t P (Process Purchase) \n\t S (Shut down)\n";
    // Perpetual Loop (Exit with Control C)
    while (indicator != "infinite")
    { // return value exits loop
        indicator = "buy"; // initalize indicator as "buy"
        cout<<MENU; // display menu
        cin>>userInput;
        firstChar = userInput.at(0); // takes first character
        cout << "\nYour Choice: " << firstChar << "\n";
	
    // P Output
        if (firstChar == "s" || firstChar == "S")
            return 0; //terminates program
        else if (firstChar != "p" && firstChar != "P")
        {
            cout<<ERROR_1<<"\n"; // Outputs error and loops continues
            indicator = "input_invalid"; //loops iteration output ends
        }
	
    // S Logic
        if (totalCredits >= 10)
        {
            cout<<"\nYou qualify for a free yogurt. ";
            cout<<" Would you like to use your credits? (Y or N) \n";
            cin>>userInput;
            if (userInput=="y" || userInput=="Y")
            {
                totalCredits -= 10; // deducts credit
                cout << "\nYou have just used 10 stamps and have ";
                cout << totalCredits<<" left.\n\n";
                indicator = "free"; // indicates free
            }
            else if (userInput != "n" && userInput != "N")
                indicator = "error"; // disqualify users for purchase
        }
        if (indicator == "buy" && (firstChar == "p" || firstChar == "P"))
        {
            cout << "\nHow many yogurts would you like to buy?: ";
            cin >> userInputInt;
            if (userInputInt > 0 && userInputInt < 50)
                totalCredits += userInputInt; // add to total credits
            else {
                cout << ERROR_3;
                indicator = "out_of_bounds";
            }
            if (indicator == "buy") {
                cout << "\nYou just earned " << userInputInt << " stamps ";
                cout << "and have a total of " << totalCredits << "\n\n";
            }
        }
        else if (indicator == "free") {
            // do nothing
        }
        else if (indicator == "error") {
            cout << ERROR_2; // print error message
        }
    } //while
    return 0;
}

/*-------------------------- RUN 1 -------------------------------
 
 Menu:
 P (process Purchase)
 S (Shut down)
 P

 Your Choice: P

 How many yogurts would you like to buy?: 12

 You just earned 12 stamps and have a total of 12

 Menu:
 P (process Purchase)
 S (Shut down)
 P

 Your Choice: P

 You qualify for a free yogurt. Would you like to use your credits? (Y or N)
 Y

 You have just used 10 stamps and have 2 left.

 Menu:
 P (process Purchase)
 S (Shut down)
 {

 Your Choice: {

 *** Use P or S, please ***

 Menu:
 P (process Purchase)
 S (Shut down)
 P

 Your Choice: P

 How many yogurts would you like to buy?: 54

 *** Value Must be in Range (0-50) ***

 Menu:
 P (process Purchase)
 S (Shut down)
 S
 
 Your Choice: S
 
 ------------------------------ Run 2 ------------------------------------
 
 Menu:
 P (process Purchase)
 S (Shut down)
 Process

 Your Choice: P

 How many yogurts would you like to buy?: 14

 You just earned 14 stamps and have a total of 14

 Menu:
 P (process Purchase)
 S (Shut down)
 P

 Your Choice: P

 You qualify for a free yogurt. Would you like to use your credits? (Y or N)
 N

 How many yogurts would you like to buy?: 34

 You just earned 34 stamps and have a total of 48

 Menu:
 P (process Purchase)
 S (Shut down)
 Pumpkin

 Your Choice: P

 You qualify for a free yogurt. Would you like to use your credits? (Y or N)
 Y

 You have just used 10 stamps and have 38 left.

 Menu:
 P (process Purchase)
 S (Shut down)
 S
 
 Your Choice: S
 
 --------------------------------------------------------------------*/

