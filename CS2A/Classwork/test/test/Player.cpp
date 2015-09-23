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