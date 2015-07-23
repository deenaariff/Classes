// TODO: The usual header stuff goes here. Don’t forget to include your Game.h
#include "Game.h"
#include "Game.cpp"

// TODO: Insert declarations of the main()’s helper functions here.

void doConfirmGuess(game,comparator,guess) {
}

void doDenyGuess (game,compartor, guess) {
}

int main(int argc, const char *argv[]) {
   char comparator;
   int guess;
   string userInput;
   const int MAX_GUESSES; 
   game.setPlayerName(getPlayerName());

   // TODO: Something is missing here, fill it in.
   
   cout <<"Welcome to Deen's Number Guessing game, " <<playerName <<".\n"
        <<"I have a non-negative number < "<< MAX_SECRET << " in mind\n"
        <<"and you have to guess it using <, > or =\n\n";
    
   while (game.getNumGuesses() < MAX_GUESSES && !game.isWon()) {
       istringstream iss;
       getline(cin, userInput);
       iss << comparator << guess; 
       if (!getGuess(game, comparator, guess))
           break;
 
       if ((comparator == '<' && game.isSecretLessThan(guess)) ||
           (comparator == '>' && game.isSecretMoreThan(guess)) ||
           (comparator == '=' && game.isSecretEqualTo(guess))) {
           doConfirmGuess(game, comparator, guess);
       } else {
           doDenyGuess(game, comparator, guess);
       }
   }
 
   if (game.isWon()) {
       cout << "Congratulations, " << game.getPlayerName() << ". "
            << "You have won the game. You took " << game.getNumGuesses()
            <<(game.getNumGuesses() > 1? " guesses.\n" : " guess.\n");
   } else {
       // TODO: Fill this in
   }
   return 0;
}
 
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
bool getGuess(const Game game, char comparator, int guess) {
   string guessStr;
 
   while(true) {
       cout << game.getNumGuesses() + 1 << ". "
            << "Enter your guess using <, =  or >, or enter Q to quit: ";
       getline(cin, guessStr);
       if (guessStr.length() == 0)
           continue;

       if (tolower(guessStr[0]) == 'q')
           return false;

       istringstream(guessStr) >>comparator >>guess;
       if (comparator == '<' || comparator == '>' || comparator == '=')
           break;

       cerr <<"Invalid comparator. Here's an example guess: "
            <<"  < 12345\n";
   }
   return true;
}

// TODO: Fill in any other helper methods used, but not defined or delcared.
