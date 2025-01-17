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