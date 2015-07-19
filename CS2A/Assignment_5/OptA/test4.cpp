// Deen

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
        cout << "Enter a string to analyze (4 or more characters): ";
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


/*------------------------ RUN 1 -----------------------------

Enter a key character: hello
ERROR: Please enter one character
Enter a key character: h
Enter a string to analyze (4 or more characters): Hi there

String with 'h' replaced:
 Hi t-ere
String with 'h' removed:
 Hi tere
Instances of 'h' in original string:
 1

------------------------- RUN 2 ------------------------------

Enter a key character: c
Enter a string to analyze (4 or more characters): crazy cats do crazy things

String with 'c' replaced:
 -razy -ats do -razy things
String with 'c' removed:
 razy ats do razy things
Instances of 'c' in original string:
 3
 
------------------------- RUN 3 ------------------------------

Enter a key character: a
Enter a string to analyze (4 or more characters): axe 
ERROR: Enter a string that is longer than 4 letters 
Enter a string to analyze (4 or more characters): the axe man scared the community

String with 'a' replaced:
 the -xe m-n sc-red the community
String with 'a' removed:
 the xe mn scred the community
Instances of 'a' in original string:
 3

------------------------- RUN 4 ------------------------------

Enter a key character: g
Enter a string to analyze (4 or more characters): go go go go go gina!

String with 'g' replaced:
 -o -o -o -o -o -ina!
String with 'g' removed:
 o o o o o ina!
Instances of 'g' in original string:
 6


------------------------- RUN 5 -----------------------------

Enter a key character: fish feed on other frenzied fish
ERROR: Please enter one character
Enter a key character: 
ERROR: Please enter one character
Enter a key character: f
Enter a string to analyze (4 or more characters): fish feed o other frenzied fish

String with 'f' replaced:
 -ish -eed o other -renzied -ish
String with 'f' removed:
 ish eed o other renzied ish
Instances of 'f' in original string:
 4

---------------------------------------------------------------*/


