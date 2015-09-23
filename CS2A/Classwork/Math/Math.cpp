//
//  Math.cpp
//  Math
//
//  Created by Deen Aariff on 8/3/15.
//  Copyright (c) 2015 Deen Aariff. All rights reserved.
//

#include "Math.h"

#include <cmath>

//  1+x+x^2/2!...

double Math::factorial (double n) {
   int result = 1;
   for (int i = n; i > 0; i--) {
      result *= i;
   }
   return result;
}

double Math::exponentiate (double x, int numberOfTerms) {
   double sum = 0;
   for (int i = 0; i < numberOfTerms; i++) {
      sum += pow(x,i) / Math::factorial(i);
   }
   return sum;
}
