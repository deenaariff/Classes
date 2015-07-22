#include <iostream>
#include <sstream>
#include <time.h>
using namespace std;

// Generate Random Number
int randomGenerate (int min, int max) {
    int randomNum = min; 
    time_t secondsElapsed = time(0); // time-dependent iteration value up to 59
    for (int i = 0; i < (secondsElapsed % 60); i++) {
        randomNum = rand() % max + min; 
    }
    return randomNum;
}

// Check if comparator is valid (return true (valid) if empty)
bool checkComparator (char comparator) {
    return (comparator == '=')? true : false;
}

// Check if User Input is Equal to Random Number
bool isEquals (int guess, int randomNum) {
    return (guess == randomNum)? true : false;
}

// Main Logic 
int main () { 
    // Header Constants 
    const string HEADER1 = "Welcome to Deen’s Number Guessing Game.\n";
    const string HEADER2 = "I have a number in mind. Can you guess it?\n";
    const string HEADER3 = "In your input below, enter the comparator\n";
    const string HEADER4 = "followed by your guess. E.g. '=15?'\n";
    // Numeric and Error Literals
    const int MIN = 1;
    const int MAX = 25; 
    const string ERROR1 = "\nERR: Only the equals comparator (=) is supported.\n\n";
    const string QUIT_SUCCESS = "Program ended with code: 0\n";
    const string QUIT_USER = "Program ended with code: 1\n";  
    // Vars  
    string userInput;
    int guesses, guess = 0;
    char comparator;
    int randomNum = randomGenerate(MIN,MAX); // Call Random Number Generator
    cout << "Random " << randomNum << endl;

    // Logic 
    cout << HEADER1 << HEADER2 << HEADER3 << HEADER4; // Print Header
    do { 
         istringstream iss; // istringstream object
         guesses ++;
         cout << "Take a guess at the number (" << MIN << "-" << MAX << "): ";
         getline (cin,userInput); // get user input
         iss.str(userInput);  
         iss >> comparator >> guess; 

         if (comparator == 'Q' || comparator == 'q') {  // user input quit 
             cout << QUIT_USER <<endl;
             break;
         }
         else if (userInput.empty()) // if string is empty (restart loop)
             continue; 
         else if (!checkComparator(comparator)) // if comparator not "=" (ERROR)
             cerr << ERROR1;
         else if (isEquals(guess, randomNum)) {  // Test guess value 
             cout << "You accomplished it with " << guesses << " tries!\n";
             cout << QUIT_SUCCESS << endl;
             break;
         }
         else 
             cout << "Nopes. Try Again\n"<< endl;;
    } while (true);
    return 0;
}
