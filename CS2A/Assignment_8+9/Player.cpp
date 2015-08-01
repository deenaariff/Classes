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
Player::Player(string name) {
    playerName = name;
    numGamesPlayed = 0;
    mostGuesses = leastGuesses = avgGuesses = INT_MAX;
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

void setNumGamesPlayed(int numGames) {
	numGamesPlayed = numGames;
}

void setMostGuesses(int guessesHigh) {
	mostGuesses = guessesHigh;
}

void setLeastGuesses(int guessesLow) {
	leastGuesses = guessesLow;
}

// Uses latest num Guesses to Calculate new Average
void setAvgGuesses(double numGuesses) {
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
;
}