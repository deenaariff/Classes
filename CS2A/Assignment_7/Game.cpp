//  Game.cpp
//  GuessIt.v1
//
//  Created by Anand Venkataraman on 7/20/14.
//  Copyright (c) 2014 Foothill College. All rights reserved.
//
#include "Game.h"
 
/**
* The constructor sets the current player's name and selects a random
* non-negative less than maxSecret
*/
Game::Game(string playerName, int maxSecret) {
   currentPlayerName = playerName;
   secretNumber = arc4random() % maxSecret;
   numGuesses = 0;
   hasBeenWon = false;
}
 
// TODO: You must flesh out the rest of this file with all the missing methods

string Game::getPlayerName() {
   return currentPlayerName;
}

void Game::setPlayerName(string playerName) {
   currentplayerName = playerName; 
}

int Game::getNumGuesses() {
   return numGuesses;
}

bool Game::isSecretLessThan(int guess) {
   return (guess > secretNumber)? true : false; 
}

bool Game::isSecretMoreThan(int guess) {
   return (guess < secretNumber)? true: false;
}

bool Game::iswon() {
   return true;
{
    
}
