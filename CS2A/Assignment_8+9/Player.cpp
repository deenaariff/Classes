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

// TODO: Implement all the getters and setters of this class

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