// TODO: The usual header stuff goes here. Don’t forget to include your Game.h
#include <iostream>
#include "Game.h"
#include "Game.cpp"
#include <sstream>
using namespace std;

// TODO: Insert declarations of the main()’s helper functions here.

// Set Game as Being won and increment number of guesses
void doConfirmGuess(Game &game, bool status) {
    int guesses = game.getNumGuesses();
    game.setNumGuesses(++guesses);
    game.setHasBeenWon(status);
}

// Game continues and increment number of guesses 
void doDenyGuess (Game game, bool status) {
    cout << "Try Again!\n";
    int guesses = game.getNumGuesses();
    game.setNumGuesses(++guesses);
    game.setHasBeenWon(status);
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

   while(true) {
       istringstream iss;
       cout << game.getNumGuesses() + 1 << ". "
            << "Enter your guess using <, =  or >, or enter Q to quit: ";
       getline(cin, guessStr);
       if (guessStr.length() == 0)
           continue;

       if (tolower(guessStr[0]) == 'q')
           return false;

       iss.str(guessStr);
       iss >> comparator >> guess; 
       if (comparator == '<' || comparator == '>' || comparator == '=')
           break;
       else {
           cerr <<"Invalid comparator. Here's an example guess: "
                <<"  < 12345\n";
       }
   }
   return true;
}

int main(int argc, const char *argv[]) {
   const int MAX_SECRET = 5;
   string playerName = getPlayerName();
   Game game = Game(playerName, MAX_SECRET);
   cout << "DEBUG: Guess is: " << game.getSecretNumber() << endl;
   char comparator;
   int guess = 0;
   string userInput;

   // TODO: Something is missing here, fill it in.
   
   cout <<"Welcome to Deen's Number Guessing game, " <<playerName <<".\n"
        <<"I have a non-negative number < "<< MAX_SECRET << " in mind\n"
        <<"and you have to guess it using <, > or =\n\n";
  
   while ((game.getNumGuesses() < MAX_SECRET) && !game.isWon()) {
       // istringstream iss;
       // getline(cin, userInput);
       // iss << comparator << guess; 
       if (!getGuess(game, comparator, guess))
           break;
 
       if ((comparator == '<' && game.isSecretLessThan(guess)) ||
           (comparator == '>' && game.isSecretMoreThan(guess)) ||
           (comparator == '=' && game.isSecretEqualTo(guess))) {
           cout << "What. What. \n";
           doConfirmGuess(game, true);
           break;
       } else {
           doDenyGuess(game, false);
       }
   }

   cout << game.isWon() << endl;
 
   if (game.isWon()) {
       cout << "Congratulations, " << playerName << ". "
            << "You have won the game. You took " << game.getNumGuesses()
            <<(game.getNumGuesses() > 1? " guesses.\n" : " guess.\n");
   } else {
      cout << "Haha " << playerName << " you lose! " 
           << "You took " << game.getNumGuesses() << " guesses!\n";
   }
   return 0;
}
 


// TODO: Fill in any other helper methods used, but not defined or delcared.
