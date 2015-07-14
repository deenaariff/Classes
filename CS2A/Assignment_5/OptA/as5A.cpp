#include <iostream>
using namespace std;

// return Key Letter from User Input
char getKeyLetter() {  
    char keyLetter;
    cout << "Enter a key letter: ";
    cin >> keyLetter;
    return keyLetter; 
}

// return String to be analyzed from User Input
string getString() {
    string theString;
    cout << "Enter a string to analyze: ";
    cin >> theString;
    return theString; 
}

// returns string with key letter replaced with "-"
string maskLetter(string theString, char keyLetter) {
    string masked;
    for (int i = 0; i < (theString.length()); i++) {
         if (theString.at(i) == keyLetter)
		masked += "-";
         else 
               masked += theString.at(i);
    }
    return masked;
}

// returns string with key letter deleted 
string removeLetter(string theString, char keyLetter) {
    string removed;
    for (int i = 0; i < theString.length(); i++) {
         if (theString.at(i) != keyLetter)
             removed += theString.at(i);
    }
    return removed;
}

// counts instances of key letter in string 
int countKey(string theString, char keyLetter) {
    int count = 0;
    for (int i = 0; i < theString.length(); i++) {
        if (theString.at(i) == keyLetter) 
              count++;
    }
    return count;
}

// main method for output 
int main () {
    char keyLetter = getKeyLetter();
    string myString = getString();
    cout << "String: " << myString << "\n";
    string masked = maskLetter(myString,keyLetter);
    string removed = removeLetter(myString,keyLetter);
    int count = countKey(myString,keyLetter); 
    cout << "Replaced: " << masked << endl;
    cout << "Removed: " << removed << endl;
    cout << "Count: " << count << endl;
    return 0;
}

