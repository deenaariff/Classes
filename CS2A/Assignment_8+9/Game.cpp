// Game.cpp
// GuessIt.v1
//
// Created by Anand Venkataraman on 7/20/14.
// Copyright (c) 2014 Pandamatak. All rights reserved.
//
#include <iostream>
#include <sstream>
#include "Game.h"
using namespace std;
// Initialize our class statics here. C++ requires it to be done this way.
int Game::numPlayers = 0;
Player Game::players[Game::MAX_PLAYERS];
/**
* The constructor sets the current player's name and selects a random
* non­negative less than MAX_SECRET
*/
Game::Game(string playerName) {
currentPlayerName = playerName;
secretNumber = arc4random() % Game::MAX_SECRET;
numGuesses = 0;
hasBeenWon = false;
}
//­­­­­­­­­­­­­­­­­­­ Static methods ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
/**
* Add the given player into our static array of Players. Return true if
* successful and false on failure (if there are already MAX_PLAYERS players).
* If there is already a player by the given name, simply return true.
*/
bool Game::addPlayer(string playerName) {
for (int i = 0; i < Game::MAX_PLAYERS; i++) {
if (Game::players[i].getPlayerName().empty()) {
Game::players[i] = Player(playerName);
++Game::numPlayers;
return true;
} else if (Game::players[i].getPlayerName().compare(playerName) == 0) {
return true; // Already existing player
}
}
return false; // Player limit reached. Couldn't add.
}
bool Game::getPlayerAtRank(...
// TODO ­ Fill in the above function definition
// Comparator to sort array of Players by increasing average number of guesses
bool avgGuessesComparator(const Player &p1, const Player &p2) {
return p1.getAvgGuesses() < p2.getAvgGuesses();
}
/**
* Sort all the players in the players array by decreasing score (i.e. by
* increasing average number of guesses.
*/
void Game::sortLeaderboard() {
sort(Game::players, Game::players + Game::MAX_PLAYERS, avgGuessesComparator);
}
int Game::getNumPlayers(void) {
return numPlayers;
}
/**
* Search linearly through the array of players and return the player
* whose name matches playerName. If no name matches when we've reached
* the end of the players array, return false. Else return true.
* The found player is returned by copying into the Player object
* passed to us by reference.
*/
bool Game::findPlayer(string playerName, Player& player) {
for (int i = 0; i < Game::MAX_PLAYERS; i++) {
if (Game::players[i].getPlayerName().compare(playerName) == 0) {
player = Game::players[i];
return true;
}
}
return false;
}
/**
* Just like findPlayer(), but update the player record which shares its name
* with the player parameter passed in. Returns false if player not found.
*/
bool Game::updatePlayer(Player& player) {
// TODO Fill in this method’s body
}
// ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
string Game::getPlayerName() const {
return currentPlayerName;
}
void Game::setPlayerName(string playerName) {
currentPlayerName = playerName;
}
int Game::getNumGuesses(void) const {
return numGuesses;
}
bool Game::isWon(void) const {
return hasBeenWon;
}
// ­­­­­­­­­­­­­­­­ Game playing logic ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
/**
* The Playing loop: The secret number has already been selected when the game
* was instantiated. The logic simply loops over user guesses, providing
* feedback if each guess was right or not. In the case of a correct equality
* guess, the loop breaks out. The loop also ends when the maximum number of
* allowed guesses has been exceeded. It returns true if the player has won
* the game.
*/
bool Game::play() {
char cmp;
int guess;
cout <<"Welcome to the Foothill Number Guessing game, " <<currentPlayerName <<".\n"
<<"I have a non­negative number < "<< Game::MAX_SECRET << " in mind\n"
<<"and you have to guess it using <, > or =\n\n";
while (numGuesses < Game::MAX_GUESSES && !hasBeenWon) {
if (!getGuess(cmp, guess))
return false;
++numGuesses;
bool isGuessCorrect;
if (cmp == '<')
isGuessCorrect = secretNumber < guess;
else if (cmp == '>')
isGuessCorrect = secretNumber > guess;
else if (cmp == '=')
hasBeenWon = isGuessCorrect = (secretNumber == guess);
cout << "\tIs SECRET " << cmp << " " << guess <<": "
<< (isGuessCorrect? "YES!\n" : "NO.\n");
}
return numGuesses < Game::MAX_GUESSES;
}
/**
* Returns the user's guess ­ the comparator and the number guessed in
* the parameters passed by reference. It returns true if these values
* were able to be filled in, and false if the user entered Q or q, signaling
* his/her intent to end the game.
*/
bool Game::getGuess(char& comparator, int& guess) const {
string guessStr;
while(true) {
cout << getNumGuesses() + 1 << ". "
<< "Enter your guess using <, = or >, or enter Q to quit: ";
getline(cin, guessStr);
if (guessStr.length() == 0)
continue;
if (tolower(guessStr[0]) == 'q')
return false;
istringstream(guessStr) >>comparator >>guess;
if (comparator == '<' || comparator == '>' || comparator == '=')
break;
cerr <<"Invalid comparator. Here's an example guess: "
<<" < 12345\n";
}
return true;
}
/**
* Update the player record for the number of guesses used up in this game, and
* update the corresponding values in the Game leaderboard. After updating values
* print the current leaderboard.
*/
void Game::updateLeaderboard(Player& player, int numGuesses) {
if (player.getMostGuesses() == INT_MAX || player.getMostGuesses() < numGuesses)
player.setMostGuesses(numGuesses);
if (player.getLeastGuesses() == INT_MAX || player.getLeastGuesses() > numGuesses)
player.setLeastGuesses(numGuesses);
// The average is a bit tricky.
// TODO: Calculate and set the average in the player’s record
// Find the player in players[] and update their stats
Game::updatePlayer(player);
Game::sortLeaderboard();
cout <<"Current Leaderboard:\n";
// TODO: Print Leaderboard by using somethng like cout << ..... << player <<endl;
cout <<"End of Leaderboard.\n\n";
}