// Assignment: 8/9
// Author: Deen Aariff
// Foothill ID: 20208433
// Creation Date: 07/31/15
// Description: Number Guessing Game With Leaderboard

/*------------------------------ Main ---------------------------------------*/

// main.cpp
// GuessIt.v1
//
// Created by Anand Venkataraman on 7/20/14.
// Copyright (c) 2014 Pandamatak. All rights reserved.
//
#include <iostream>
#include <sstream>

#include "Game.cpp"


using namespace std;

string getPlayerName(void);
void updatePlayerRecord(Game& game, Player& player, int numGuesses);

/**
 * The number guessing game with a leaderboard. Everyone can play this game.
 * Everyone, that is, except, apparently, Mr. Q (Is he a character in
 * Star Trek TNG? I never liked him, I think. Serves him right.)
 */

int main(int argc, const char * argv[]) {
   while(true) {
      string playerName = getPlayerName();
      if (playerName.compare("Q") == 0 || playerName.compare("q") == 0)
         break;
      if (!Game::addPlayer(playerName)) {
         cerr << "Sorry. No more new players. Only accepting known players.\n";
         continue;
      }
      Player player;
      player.setPlayerName(playerName);
      if (!Game::findPlayer(playerName, player)) {
         cerr << "Something's wrong! I can't find a player"
         <<  "who ought to exist!\n"
         << "We'll look into this, I promise\n";
         continue;
      }
      // At this point the player exists and we hold his/her record in the
      // variable: player.
      Game game(playerName);
      game.play();
      if (game.isWon()) {
         cout << "Congratulations, " << game.getPlayerName() << ". "
         << "You have won the game. You took " << game.getNumGuesses()
         <<(game.getNumGuesses() > 1? " guesses.\n" : " guess.\n");
         Game::updateLeaderboard(player, game.getNumGuesses());
      } else {
         cout <<"I'm sorry, " << game.getPlayerName() << ". "
         << "You did not win the game after " << game.getNumGuesses()
         << (game.getNumGuesses() > 1? " guesses.\n" : " guess.\n");
         Game::updateLeaderboard(player, Game::MAX_GUESSES);
      }
   }
   cout << "Bye!\n";
   return 0;
}

string getPlayerName() {
   string name = "";
   while (name.length() == 0) {
      cout << "Hello playa, whatcha name ('Q' to quit)? ";
      getline(cin, name);
   }
   return name;
}

/*--------------------------- Game.h ------------------------------------*/

// Game.h
// GuessIt.v2
//
// Created by Anand Venkataraman on 7/20/14.
// Copyright (c) 2014 Pandamatak. All rights reserved.
//

#ifndef __GuessIt_v1__Game__
#define __GuessIt_v1__Game__

#include <iostream>
#include "Player.cpp"
using namespace std;

/**
 * The Game class not only provides the game logic, but also keeps the Game
 * Leaderboard in a static array of players. Currently, it allows up to
 * MAX_PLAYERS players to enter the leaderboard. If a new player tries to play
 * the game when MAX_PLAYERS players are in the leaderboard already, the game
 * will reject them (not allow them to play).
 */

class Game {
public:
   static const int MAX_GUESSES = 50;
   static const int MAX_PLAYERS = 3;
   static const long MAX_SECRET = 1000000;
   static Player players[MAX_PLAYERS];

private:
   static int numPlayers;
   static void sortLeaderboard();
   static bool getPlayerAtRank(int i, Player& player);
   int secretNumber; // Neither getter nor setter for this
   string currentPlayerName;
   bool hasBeenWon;
   int numGuesses;

public:
   Game(string playerName);
   static bool addPlayer(string playerName);
   static int getNumPlayers(void);
   static bool findPlayer(string PlayerName, Player& player);
   static bool updatePlayer(Player& player);
   static void updateLeaderboard(Player& player, int numGuesses);

   string getPlayerName(void) const;
   int getNumGuesses(void) const;
   void setPlayerName(string playerName);
   bool isWon(void) const;
   bool getGuess(char& comparator, int& guess) const;
   bool play();
};

#endif /* defined(__GuessIt_v1__Game__) */


/*-------------------------- Game.cpp --------------------------------------*/

// Game.cpp
// GuessIt.v1
//
// Created by Anand Venkataraman on 7/20/14.
// Copyright (c) 2014 Pandamatak. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Game.h"


using namespace std;
// Initialize our class statics here. C++ requires it to be done this way.
int Game::numPlayers = 0;
Player Game::players[Game::MAX_PLAYERS];

/**
 * The constructor sets the current player's name and selects a random
 * nonÂ­negative less than MAX_SECRET
 */

Game::Game(string playerName) {
   currentPlayerName = playerName;
   secretNumber = arc4random() % Game::MAX_SECRET;
   numGuesses = 0;
   hasBeenWon = false;
}

//------------------------- Static methods ---------------------------------
/**
 * Add the given player into our static array of Players. Return true if
 * successful and false on failure (if there are already MAX_PLAYERS players).
 * If there is already a player by the given name, simply return true.
 */
bool Game::addPlayer(string playerName) {
   for (int i = 0; i < Game::MAX_PLAYERS; i++) {
      if (Game::players[i].getPlayerName().compare(playerName) == 0) {
         return true; // Already existing player
      }
      else if (Game::players[i].getPlayerName().empty()) {
         Game::players[i] = Player();
         Game::players[i].setPlayerName(playerName);
         ++Game::numPlayers;
         return true;
      }
   }
   return false; // Player limit reached. Couldn't add.
}


/**
 * Checks to see if player at index i is same as player paramater passed
 * If true player at index i is updated, returns true
 * else returns false
 */
bool Game::getPlayerAtRank(int i, Player& player) {
   // DONE Fill in the above function definition
   // Comparator to sort array of Players by increasing avg number of guesses
   if (Game::players[i].getPlayerName() == player.getPlayerName()) {
      Game::players[i] = player; // more efficient than updatePlayer()
      return true;
   }
   else
      return false;
}

bool avgGuessesComparator(const Player &p1, const Player &p2) {
   return p1.getAvgGuesses() < p2.getAvgGuesses();
}

/**
 * Sort all the players in the players array by decreasing score (i.e. by
 * increasing average number of guesses.
 */
void Game::sortLeaderboard() {
   sort(Game::players, Game::players + Game::MAX_PLAYERS, avgGuessesComparator);
}

int Game::getNumPlayers(void) {
   return numPlayers;
}

/**
 * Search linearly through the array of players and return the player
 * whose name matches playerName. If no name matches when we've reached
 * the end of the players array, return false. Else return true.
 * The found player is returned by copying into the Player object
 * passed to us by reference.
 */
bool Game::findPlayer(string playerName, Player& player) {
   for (int i = 0; i < Game::MAX_PLAYERS; i++) {
      if (Game::players[i].getPlayerName().compare(playerName) == 0) {
         player = Game::players[i];
         return true;
      }
   }
   return false;
}

/**
 * Just like findPlayer(), but update the player record which shares its name
 * with the player parameter passed in. Returns false if player not found.
 */
bool Game::updatePlayer(Player& player) {
   // DONE Fill in this methodâ€™s body
   for (int i = 0; i < numPlayers; i++) {
      if (Game::players[i].getPlayerName().compare(player.getPlayerName())==0){
         Game::players[i] = player;
         return true;
      }
   }
   return false;
}

string Game::getPlayerName() const {
   return currentPlayerName;
}

void Game::setPlayerName(string playerName) {
   currentPlayerName = playerName;
}

int Game::getNumGuesses(void) const {
   return numGuesses;
}

bool Game::isWon(void) const {
   return hasBeenWon;
}

// -------------------- Game playing logic ------------------------------
/**
 * The Playing loop: The secret number has already been selected when the game
 * was instantiated. The logic simply loops over user guesses, providing
 * feedback if each guess was right or not. In the case of a correct equality
 * guess, the loop breaks out. The loop also ends when the maximum number of
 * allowed guesses has been exceeded. It returns true if the player has won
 * the game.
 */
bool Game::play() {
   char cmp;
   int guess;
   cout << "Welcome to the Foothill Number Guessing game, "
   << currentPlayerName <<".\n"
   << "I have a nonÂ­negative number < "<< MAX_SECRET << " in mind\n"
   << "and you have to guess it using <, > or =\n\n";
   while (numGuesses < Game::MAX_GUESSES && !hasBeenWon) {
      if (!getGuess(cmp, guess))
         return false;
      ++numGuesses;
      bool isGuessCorrect;
      if (cmp == '<')
         isGuessCorrect = secretNumber < guess;
      else if (cmp == '>')
         isGuessCorrect = secretNumber > guess;
      else if (cmp == '=')
         hasBeenWon = isGuessCorrect = (secretNumber == guess);
      cout << "\tIs SECRET " << cmp << " " << guess <<": "
      << (isGuessCorrect? "YES!\n" : "NO.\n");
   }
   return numGuesses < Game::MAX_GUESSES;
}

/**
 * Returns the user's guess Â­ the comparator and the number guessed in
 * the parameters passed by reference. It returns true if these values
 * were able to be filled in, and false if the user entered Q or q, signaling
 * his/her intent to end the game.
 */
bool Game::getGuess(char& comparator, int& guess) const {
   string guessStr;
   istringstream iss;
   while(true) {
      cout << getNumGuesses() + 1 << ". "
      << "Enter your guess using <, = or >, or enter Q to quit: ";
      getline(cin, guessStr);
      if (guessStr.length() == 0)
         continue;
      if (tolower(guessStr[0]) == 'q')
         return false;
      iss.str(guessStr);
      iss >> comparator >> guess;
      if (comparator == '<' || comparator == '>' || comparator == '=')
         break;
      cerr << "Invalid comparator. Here's an example guess: " <<" < 12345\n";
   }
   return true;
}

/**
 * Update the player record for the number of guesses used up in this game, and
 * update the corresponding values in the Game leaderboard.
 * print the current leaderboard after updating values.
 */
void Game::updateLeaderboard(Player& player, int numGuesses) {
   if (player.getMostGuesses()== INT_MAX ||
       player.getMostGuesses()< numGuesses)
      player.setMostGuesses(numGuesses);
   if (player.getLeastGuesses()== INT_MAX ||
       player.getLeastGuesses() >numGuesses)
      player.setLeastGuesses(numGuesses);
   // The average is a bit tricky.
   // DONE: Calculate and set the average in the playerâ€™s record
   int numGames = player.getNumGamesPlayed();
   player.setAvgGuesses(numGuesses);
   player.setNumGamesPlayed(++numGames);
   // Find the player in players[] and update their stats
   updatePlayer(player);
   sortLeaderboard();
   cout <<"Current Leaderboard:\n\n";
   // DONE: Print Leaderboard by using somethng like cout << ..... << player
   for (int i = 0; i < getNumPlayers(); i++) {
      int rankVal = i + 1;
      cout << "Rank " << rankVal << ": " << players[i] << endl;
   }
   cout << endl;
   cout <<"End of Leaderboard.\n\n";
}

/*------------------------- Player.h ----------------------------------*/

// Player.h
// Guessit.v2
//
// Created by Anand Venkataraman on 7/20/14.
// Copyright (c) 2014 Foothill College. All rights reserved.
//

#ifndef __Guessit_v2__Player__
#define __Guessit_v2__Player__

#include <iostream>
using namespace std;

/**
 * The Player class represents a single player. It keeps track of his or her
 * best score (least number of guesses) worst score (most), number of games
 * played and the average number of gueses over all games. Note that you can
 * always calculate a new average given a new game with the number of guesses
 * taken in it from just the existing statistics in a player object .
 */
class Player {

public:
   Player(); // Note optional param and default.

   string getPlayerName(void) const;
   int getNumGamesPlayed(void) const;
   int getMostGuesses(void) const;
   int getLeastGuesses(void) const;
   double getAvgGuesses(void) const;

   void setPlayerName(string name);
   void setNumGamesPlayed(int numGames);
   void setMostGuesses(int guessesHigh);
   void setLeastGuesses(int guessesLow);
   void setAvgGuesses(int numGuesses);

private:
   string playerName;
   int numGamesPlayed;
   int leastGuesses;
   int mostGuesses;
   double avgGuesses;
};


// We want to pretty print the Player object with << and hence this.
ostream& operator<<(ostream& os, const Player& player);

#endif /* defined(__Guessit_v2__Player__) */


/*---------------------------- Player.cpp --------------------------------*/

// Player.cpp
// Guessit.v2
//
// Created by Anand Venkataraman on 7/20/14.
// Copyright (c) 2014 Foothill College. All rights reserved.
//
#include <iostream>
#include "Player.h"



using namespace std;

/**
 * name is an optional param (See the class decl). It defaults to ""
 */
Player::Player() {
   numGamesPlayed = 0;
   mostGuesses = leastGuesses = avgGuesses = INT_MAX;
};

// DONE: Implement all the getters and setters of this class
string Player::getPlayerName(void) const {
   return playerName;
}

int Player::getNumGamesPlayed(void) const {
   return numGamesPlayed;
}

int Player::getMostGuesses(void) const {
   return mostGuesses;
}

int Player::getLeastGuesses(void) const {
   return leastGuesses;
}

double Player::getAvgGuesses(void) const {
   return avgGuesses;
}

void Player::setPlayerName(string name) {
   playerName = name;
}

void Player::setNumGamesPlayed(int numGames) {
   numGamesPlayed = numGames;
}

void Player::setMostGuesses(int guessesHigh) {
   mostGuesses = guessesHigh;
}

void Player::setLeastGuesses(int guessesLow) {
   leastGuesses = guessesLow;
}

// Uses latest num Guesses to Calculate new Average
void Player::setAvgGuesses(int numGuesses) {
   if (numGuesses < 1)
      avgGuesses = 0;
   avgGuesses = ((avgGuesses*numGamesPlayed)+numGuesses)/(numGamesPlayed+1);
}

/**
 * The output operator << on the Player data type. It
 * pretty prints the members of this player.
 */
ostream& operator<<(ostream& os, const Player& player) {
   return os <<player.getPlayerName() << ": "
   <<player.getNumGamesPlayed() << " Games. "
   <<"Guesses: "
   <<player.getAvgGuesses() << " (avg) "
   <<player.getLeastGuesses() << " (best) "
   <<player.getMostGuesses() << " (worst) ";
}

/*------------------------------ RUN ------------------------------------

 Hello playa, whatcha name ('Q' to quit)? Deen
 Welcome to the Foothill Number Guessing game, Deen.
 I have a nonÂ­negative number < 1000000 in mind
 and you have to guess it using <, > or =

 1. Enter your guess using <, = or >, or enter Q to quit: >500000
 Is SECRET > 500000: NO.
 2. Enter your guess using <, = or >, or enter Q to quit: >250000
 Is SECRET > 250000: YES!
 3. Enter your guess using <, = or >, or enter Q to quit: >370000
 Is SECRET > 370000: YES!
 4. Enter your guess using <, = or >, or enter Q to quit: >420000
 Is SECRET > 420000: NO.
 5. Enter your guess using <, = or >, or enter Q to quit: >400000
 Is SECRET > 400000: NO.
 6. Enter your guess using <, = or >, or enter Q to quit: >380000
 Is SECRET > 380000: NO.
 7. Enter your guess using <, = or >, or enter Q to quit: >375000
 Is SECRET > 375000: NO.
 8. Enter your guess using <, = or >, or enter Q to quit: >372000
 Is SECRET > 372000: NO.
 9. Enter your guess using <, = or >, or enter Q to quit: >371000
 Is SECRET > 371000: NO.
 10. Enter your guess using <, = or >, or enter Q to quit: >370500
 Is SECRET > 370500: YES!
 11. Enter your guess using <, = or >, or enter Q to quit: >370750
 Is SECRET > 370750: NO.
 12. Enter your guess using <, = or >, or enter Q to quit: >370600
 Is SECRET > 370600: YES!
 13. Enter your guess using <, = or >, or enter Q to quit: >370700
 Is SECRET > 370700: NO.
 14. Enter your guess using <, = or >, or enter Q to quit: >370650
 Is SECRET > 370650: YES!
 15. Enter your guess using <, = or >, or enter Q to quit: >370675
 Is SECRET > 370675: YES!
 16. Enter your guess using <, = or >, or enter Q to quit: >370690
 Is SECRET > 370690: NO.
 17. Enter your guess using <, = or >, or enter Q to quit: >370680
 Is SECRET > 370680: YES!
 18. Enter your guess using <, = or >, or enter Q to quit: >370685
 Is SECRET > 370685: NO.
 19. Enter your guess using <, = or >, or enter Q to quit: >370682
 Is SECRET > 370682: NO.
 20. Enter your guess using <, = or >, or enter Q to quit: =370681
 Is SECRET = 370681: NO.
 21. Enter your guess using <, = or >, or enter Q to quit: =370680
 Is SECRET = 370680: NO.
 22. Enter your guess using <, = or >, or enter Q to quit: =370682
 Is SECRET = 370682: YES!
 Congratulations, Deen. You have won the game. You took 22 guesses.
 Current Leaderboard:

 Rank 1: Deen: 1 Games. Guesses: 22 (avg) 22 (best) 22 (worst)

 End of Leaderboard.

 Hello playa, whatcha name ('Q' to quit)? John
 Welcome to the Foothill Number Guessing game, John.
 I have a nonÂ­negative number < 1000000 in mind
 and you have to guess it using <, > or =

 1. Enter your guess using <, = or >, or enter Q to quit: > 500000
 Is SECRET > 500000: NO.
 2. Enter your guess using <, = or >, or enter Q to quit: >250000
 Is SECRET > 250000: NO.
 3. Enter your guess using <, = or >, or enter Q to quit: >100000
 Is SECRET > 100000: NO.
 4. Enter your guess using <, = or >, or enter Q to quit: >50000
 Is SECRET > 50000: NO.
 5. Enter your guess using <, = or >, or enter Q to quit: >0
 Is SECRET > 0: YES!
 6. Enter your guess using <, = or >, or enter Q to quit: >25000
 Is SECRET > 25000: NO.
 7. Enter your guess using <, = or >, or enter Q to quit: >10000
 Is SECRET > 10000: YES!
 8. Enter your guess using <, = or >, or enter Q to quit: >15000
 Is SECRET > 15000: YES!
 9. Enter your guess using <, = or >, or enter Q to quit: >20000
 Is SECRET > 20000: NO.
 10. Enter your guess using <, = or >, or enter Q to quit: >17500
 Is SECRET > 17500: YES!
 11. Enter your guess using <, = or >, or enter Q to quit: >18750
 Is SECRET > 18750: YES!
 12. Enter your guess using <, = or >, or enter Q to quit: >19000
 Is SECRET > 19000: YES!
 13. Enter your guess using <, = or >, or enter Q to quit: >19500
 Is SECRET > 19500: NO.
 14. Enter your guess using <, = or >, or enter Q to quit: >19250
 Is SECRET > 19250: NO.
 15. Enter your guess using <, = or >, or enter Q to quit: >19100
 Is SECRET > 19100: YES!
 16. Enter your guess using <, = or >, or enter Q to quit: >19200
 Is SECRET > 19200: YES!
 17. Enter your guess using <, = or >, or enter Q to quit: >19225
 Is SECRET > 19225: YES!
 18. Enter your guess using <, = or >, or enter Q to quit: >19235
 Is SECRET > 19235: YES!
 19. Enter your guess using <, = or >, or enter Q to quit: >19240
 Is SECRET > 19240: YES!
 20. Enter your guess using <, = or >, or enter Q to quit: >19245
 Is SECRET > 19245: NO.
 21. Enter your guess using <, = or >, or enter Q to quit: >19242
 Is SECRET > 19242: NO.
 22. Enter your guess using <, = or >, or enter Q to quit: >19241
 Is SECRET > 19241: YES!
 23. Enter your guess using <, = or >, or enter Q to quit: =19242
 Is SECRET = 19242: YES!
 Congratulations, John. You have won the game. You took 23 guesses.
 Current Leaderboard:

 Rank 1: Deen: 1 Games. Guesses: 22 (avg) 22 (best) 22 (worst)
 Rank 2: John: 1 Games. Guesses: 23 (avg) 23 (best) 23 (worst)

 End of Leaderboard.

 Hello playa, whatcha name ('Q' to quit)? Gregory
 Welcome to the Foothill Number Guessing game, Gregory.
 I have a nonÂ­negative number < 1000000 in mind
 and you have to guess it using <, > or =

 1. Enter your guess using <, = or >, or enter Q to quit: >500000
 Is SECRET > 500000: NO.
 2. Enter your guess using <, = or >, or enter Q to quit: >250000
 Is SECRET > 250000: YES!
 3. Enter your guess using <, = or >, or enter Q to quit: >300000
 Is SECRET > 300000: YES!
 4. Enter your guess using <, = or >, or enter Q to quit: >400000
 Is SECRET > 400000: YES!
 5. Enter your guess using <, = or >, or enter Q to quit: >450000
 Is SECRET > 450000: NO.
 6. Enter your guess using <, = or >, or enter Q to quit: >425000
 Is SECRET > 425000: NO.
 7. Enter your guess using <, = or >, or enter Q to quit: >410000
 Is SECRET > 410000: NO.
 8. Enter your guess using <, = or >, or enter Q to quit: >405000
 Is SECRET > 405000: NO.
 9. Enter your guess using <, = or >, or enter Q to quit: >402500
 Is SECRET > 402500: YES!
 10. Enter your guess using <, = or >, or enter Q to quit: >403500
 Is SECRET > 403500: NO.
 11. Enter your guess using <, = or >, or enter Q to quit: >403000
 Is SECRET > 403000: YES!
 12. Enter your guess using <, = or >, or enter Q to quit: >403250
 Is SECRET > 403250: YES!
 13. Enter your guess using <, = or >, or enter Q to quit: >403300
 Is SECRET > 403300: YES!
 14. Enter your guess using <, = or >, or enter Q to quit: >403400
 Is SECRET > 403400: NO.
 15. Enter your guess using <, = obr >, or enter Q to quit: >403350
 Is SECRET > 403350: YES!
 16. Enter your guess using <, = or >, or enter Q to quit: >403375
 Is SECRET > 403375: YES!
 17. Enter your guess using <, = or >, or enter Q to quit: >403385
 Is SECRET > 403385: YES!
 18. Enter your guess using <, = or >, or enter Q to quit: >403395
 Is SECRET > 403395: YES!
 19. Enter your guess using <, = or >, or enter Q to quit: >403397
 Is SECRET > 403397: YES!
 20. Enter your guess using <, = or >, or enter Q to quit: >403398
 Is SECRET > 403398: YES!
 21. Enter your guess using <, = or >, or enter Q to quit: =403399
 Is SECRET = 403399: NO.
 22. Enter your guess using <, = or >, or enter Q to quit: =403400
 Is SECRET = 403400: YES!
 Congratulations, Gregory. You have won the game. You took 22 guesses.
 Current Leaderboard:

 Rank 1: Deen: 1 Games. Guesses: 22 (avg) 22 (best) 22 (worst)
 Rank 2: Gregory: 1 Games. Guesses: 22 (avg) 22 (best) 22 (worst)
 Rank 3: John: 1 Games. Guesses: 23 (avg) 23 (best) 23 (worst)

 End of Leaderboard.

 Hello playa, whatcha name ('Q' to quit)? Bill
 Sorry. No more new players. Only accepting known players.
 Hello playa, whatcha name ('Q' to quit)

 -----------------------------------------------------------------------*/