// Assignment: 6A
// Author: Deen Aariff
// Foothill ID: 20208433
// Creation Date: 07/21/15
// Description: Number Guessing Game Simple

// TODO: The usual header stuff goes here. Don’t forget to include your Game.h
#include <iostream>
#include "Game.h"
#include "Game.cpp"
#include <sstream>
using namespace std;

// TODO: Insert declarations of the main()’s helper functions here.

// Set Game as Being won and increment number of guesses
void doConfirmGuess(char comparator, int guess) {
    cout << "You asked if " << comparator << " " << guess << ": ";
    cout << "YES!\n";
}

// Game continues and increment number of guesses 
void doDenyGuess (char comparator, int guess) {
    cout << "You asked if " << comparator << " " << guess << ": ";
    cout << "NO!\n";
}

// Return Player Name from User Input 
string getPlayerName() {
   string name = "";
   while (name.length() == 0) {
       cout << "Hello playa, whatcha name? ";
       getline(cin, name);
   }
   return name;
}
 
/**
* Returns the user's guess - the comparator and the number guessed in
* the parameters passed by reference. It returns true if these values
* were able to be filled in, and false if the user entered Q or q, signaling
* his/her intent to end the game.
*/
// TODO: The following signature is WRONG. FIX IT!
bool getGuess(Game game, char &comparator, int &guess) {
   string guessStr;
   const string QUIT_USER = "Exit Code: 1\n";

   while(true) {
       istringstream iss;
       cout << game.getNumGuesses() + 1 << ". "
            << "Enter your guess using <, =  or >, or enter Q to quit: ";
       getline(cin, guessStr);
       iss.str(guessStr);
       iss >> comparator >> guess; 

       if (guessStr.length() == 0)
           continue;

       if (tolower(guessStr[0]) == 'q') {
           cout << QUIT_USER;
           return false;
       }

       if (comparator == '<' || comparator == '>' || comparator == '=')
           break;
       else {
           cerr <<"Invalid comparator or value. Here's an example guess: "
                <<"  < 12345\n";
       }
   }
   return true;
}

// Main Logic
int main(int argc, const char *argv[]) {
   const int MAX_GUESSES = 30; // maximum number of guesses
   const int MAX_SECRET = 1000000; // maximum value of secret number
   string playerName = getPlayerName();
   Game game = Game(playerName, MAX_SECRET);
   char comparator;
   int guess,guesses = 0;
   string userInput;

   // TODO: Something is missing here, fill it in.
   
   cout <<"Welcome to Deen's Number Guessing game, " <<playerName <<".\n"
        <<"I have a non-negative number < "<< MAX_SECRET << " in mind\n"
        <<"and you have to guess it using <, > or =\n\n";
  
   while ((game.getNumGuesses() < MAX_GUESSES) && !game.isWon()) {
       if (!getGuess(game, comparator, guess))
           break;
       
       // Increment Guesses # and Set Class Object Value
       game.setNumGuesses(++guesses); 

       if ((comparator == '<' && game.isSecretLessThan(guess)) ||
           (comparator == '>' && game.isSecretMoreThan(guess)) ||
           (comparator == '=' && game.isSecretEqualTo(guess))) {
           if (guesses < MAX_GUESSES)
               doConfirmGuess(comparator, guess);
       } else {
           doDenyGuess(comparator, guess);
       }
   }
   
   if (game.isWon()) {
       cout << "\nCongratulations, " << playerName << "! "
           << "You have won the game. You took " << game.getNumGuesses()
           <<(game.getNumGuesses() > 1? " guesses.\n" : " guess.\n");
   } else if (!(comparator == 'q' || comparator == 'Q')) {
      cout << "\nHaha " << playerName << " you lose! " 
           << "You took " << game.getNumGuesses()
           << (game.getNumGuesses() > 1? " guesses" : " guess")
           << ", which is more than the allowed amount.\n";
   }
   return 0;
}
 


// TODO: Fill in any other helper methods used, but not defined or delcared.
