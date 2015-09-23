//
//  execute.cpp
//  
//
//  Created by Deen Aariff on 8/3/15.
//
//

#include <stdio.h>
#include <solve.cpp>

int main () {
   const double NUM_TERMS = 5;
   double result = Solve::exponentiate(1,NUM_TERMS);
   cout << "e^" << 1 << " = " << result << endl;
   return 0;
}

