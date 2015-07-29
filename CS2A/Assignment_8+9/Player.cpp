// Player.cpp
// Guessit.v2
//
// Created by Anand Venkataraman on 7/20/14.
// Copyright (c) 2014 Foothill College. All rights reserved.
//
#include "Player.h"
#include "Game.h"

using namespace std;

/**
* name is an optional param (See the class decl). It defaults to ""
*/
Player::Player(string name) {
    playerName = name;
    numGamesPlayed = 0;
    mostGuesses = leastGuesses = avgGuesses = INT_MAX;
}

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

double getAvgGuesses(void) const {
	return avgGuesses;
}

void setPlayerName(string name) {
	playerName = name;
}

void setNumGamesPlayed(int n) {
	numGamesPlayed = n;
}

void setMostGuesses(int n) {
	mostGuesses = n;
}

void setLeastGuesses(int n) {
	leastGuesses = n;
}

void setAvgGuesses(double x) {
	avgGuesses = x;
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
        <<player.getMostGuesses() << " (worst) "
;
}