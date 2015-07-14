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
    string String;
    cout << "Enter a string to analyze: ";
    cin >> String;
    return String; 
}

// returns string with key letter replaced with "-"
string maskLetter(string theString, char keyLetter) {
    cout << "initialized";
    string masked;
    for (int i = 0; i < sizeof(theString)-1; i++) {
	 cout << "working for i:" << i;
         if (theString.at(i) == keyLetter)
		masked += '-';
         else 
               masked += theString.at(i);
    }
    return masked;
}

// returns string with key letter deleted 
string removeLetter(string theString, char keyLetter) {
    string removed;
    for (int i = 0; i <sizeof(theString); i++) {
         if (theString.at(i) != keyLetter)
             removed.at(i) += theString.at(i);
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
    return count;
}

// main method for output 
int main () {
    char keyLetter = getKeyLetter();
    string myString = getString();
    cout << maskLetter(myString,keyLetter);
    cout << removeLetter(myString,keyLetter);
    cout << countKey(myString,keyLetter); 
    return 0;
}

