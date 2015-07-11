#include <iostream>
using namespace std;

// return Key Letter from User Input
char getKeyLetter() {  
    char letter;
    cout << "Enter a key letter: ";
    cin >> letter;
    return letter; 
}

// return String to be analyzed from User Input
string getString() {
    string String;
    cout << "Enter a string to analyze: ";
    cin >> String;
    return String; 
}

// returns string with key letter replaced with "-"
string maskLetter(string theString, char keyLetter) {
    string masked;
    for (int i = 0; i < sizeof(theString); i++) {
         if (theString.at(i) == keyLetter)
		masked.at(i) = '-';
         else 
               masked.at(i) = theString.at(i);
    }
    return masked;
}

// returns string with key letter deleted 
string removeLetter(string theString, char keyLetter) {
    string removed;
    for (int i = 0; i <sizeof(theString); i++) {
         if (theString.at(i) != keyLetter)
             removed.at(i) = theString.at(i);
    }
    return removed;
}

// counts instances of key letter in string 
int countKey(string theString, char keyLetter) {
    int count;
    for (int i = 0; i < sizeof(theString); i++) {
        if (theString.at(i) == keyLetter ) 
              count++;
    }
    return 0;
}

// main method for output 
int main () {
    return 0;
}

