// Game.h
// GuessIt.v2
//
// Created by Anand Venkataraman on 7/20/14.
// Copyright (c) 2014 Pandamatak. All rights reserved.
//

#ifndef __GuessIt_v1__Game__
#define __GuessIt_v1__Game__

#include <iostream>
#include "Player.h"
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
    static const int MAX_PLAYERS = 10;
    static const long MAX_SECRET = 1000000;
    
private:
    static Player players[MAX_PLAYERS];
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