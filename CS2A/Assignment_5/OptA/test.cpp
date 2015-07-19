#include <iostream>
#include <string>
using namespace std;

// return Key Letter from User Input
char getKeyLetter() {
    string keyLetter;
    while(true) {
        cout << "Enter a key character: ";
        getline(cin,keyLetter);
        if (keyLetter.length() == 1)
            break;
        else
            cout << "ERROR: Please enter one character\n"; // User Error
    }
    return keyLetter.at(0);
}

// return String to be analyzed from User Input
string getString() {
    string theString;
    while(true) {
        cout << "Enter a string to analyze: ";
        getline(cin,theString);
        if (theString.length() >= 4) 
             break;
        else 
            cout << "ERROR: Enter a string that is longer than 4 letters \n";
    }
    return theString;
}

// returns string with key letter replaced with "-"
string maskLetter(string theString, char keyLetter) {
    string masked = "";
    for (int i = 0; i < (theString.length()); i++) {
        if (theString.at(i) == keyLetter)
            masked += "-";  // concatenate string with "-"
        else
            masked += theString.at(i); // concatenate  original character at i
    }
    return masked;
}

// returns string with key letter deleted 
string removeLetter(string theString, char keyLetter) {
    string removed = "";
    for (int i = 0; i < theString.length(); i++) {
        if (theString.at(i) != keyLetter)
        removed += theString.at(i); // concatenate string with index of i
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
    string masked = maskLetter(myString,keyLetter);
    string removed = removeLetter(myString,keyLetter);
    int count = countKey(myString,keyLetter); 
    cout << "\nString with '" << keyLetter;
    cout << "' replaced:\n " << masked << endl;
    cout << "String with '" << keyLetter;
    cout<< "' removed:\n " << removed << endl;
    cout<< "Instances of '" << keyLetter;
    cout<< "' in original string:\n " << count << endl;
    return 0;
}

