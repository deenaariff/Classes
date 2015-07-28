//  Game.h
//  GuessIt.v1
//
//  Created by Anand Venkataraman on 7/20/14.
//  Copyright (c) 2014 Foothill College. All rights reserved.
//
#ifndef __GuessIt_v1__Game__
#define __GuessIt_v1__Game__

#include <iostream>
using namespace std;

class Game {
private:
   int secretNumber; // Neither getter nor setter
   string currentPlayerName;
   bool hasBeenWon;
   int numGuesses;

public:
   Game(string playerName, int maxSecret);

   void setHasBeenWon(bool status);

   string getPlayerName(void) const;
   void setPlayerName(string playerName);

   int getNumGuesses(void) const;
   void setNumGuesses(int guesses);

   bool isSecretLessThan(int guess);
   bool isSecretMoreThan(int guess);
   bool isSecretEqualTo(int guess);

   bool isWon(void) const;
};

#endif /* defined(__GuessIt_v1__Game__) */
