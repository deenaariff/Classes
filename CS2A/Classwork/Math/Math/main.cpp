//
//  main.cpp
//  Math
//
//  Created by Deen Aariff on 8/3/15.
//  Copyright (c) 2015 Deen Aariff. All rights reserved.
//
#include <iostream>
#include <cmath>
using namespace std;

#include "Math.h"

int main () {
   const double NUM_TERMS = 20;
   double result = Math::exponentiate(2,NUM_TERMS);
   cout << "e^" << 2 << " = " << result << endl;
   double error = result - exp(2.0);
   cout << "ERROR: " << error << endl;
   return 0;
}