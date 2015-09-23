//
//  solve.cpp
//  
//
//  Created by Deen Aariff on 8/3/15.
//
//

#include "solve.h"
#include <cmath>

//  1+x+x^2/2!...

double Solve::factorial (double n) {
   int result = 1;
   for (int i = n; i > 0; i--) {
      result *= i;
   }
   return result;
}

double Solve::exponentiate (double x, int numberOfTerms) {
   double sum = 0;
   for (int i = 0; i < numberOfTerms; i++) {
      sum += pow(x,i) / Solve::factorial(i);
   }
   return sum;
}


