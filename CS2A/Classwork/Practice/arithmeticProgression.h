#ifndef _Temp_ArithmeticProgression_
#define _Temp_ArithmeticProgression_

#include <stdio.h>

class ArithmeticProgression {
private:
    double firstTerm;
    double diff;

public: 
    ArithmeticProgression(double first, double diff);
    double getNthTerm(int n);
    double getSumOfTerms(int n); 
};

#endif
