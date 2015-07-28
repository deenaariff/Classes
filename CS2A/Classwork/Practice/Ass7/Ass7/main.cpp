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

void Game::setHasBeenWon(bool status) {
   hasBeenWon = status;
}

string Game::getPlayerName() const {
   return currentPlayerName;
}

void Game::setPlayerName(string playerName) {
   currentPlayerName = playerName;
}

int Game::getNumGuesses() const {
   return numGuesses;
}

void Game::setNumGuesses(int guesses) {
   numGuesses = guesses;
}

bool Game::isSecretLessThan(int guess) {
   return (guess > secretNumber)? true : false;
}

bool Game::isSecretMoreThan(int guess) {
   return (guess < secretNumber)? true: false;
}

bool Game::isSecretEqualTo(int guess) {
   return (guess == secretNumber)? true : false;
}

bool Game::isWon() const {
   return hasBeenWon;
}

