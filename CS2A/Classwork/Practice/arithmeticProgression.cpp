#include <iostream>
#include <sstream> 
#include <string> 
#include "ArithmeticProgression.h"
using namespace std;

ArithmeticProgression::ArithmeticProgression (double first, double d) {
    this->firstTerm = first; // members
    this->diff = d; 

// "this means current object, -> derefferences an objects (takes conents of pointer and pass it to that variable)
};

double ArithmeticProgression::getNthTerm(int n) {
    double nthTerm = firstTerm + diff*n;
    return nthTerm;
}

double ArithmeticProgression::getSumOfTerms (int n) { 
    double sum;
    sum = (n/2) * (2*firstTerm + (n-1)*diff);
    return sum;
}

int main () {
    ArithmeticProgression test (1,1);
    ArithmeticProgression prog = test;
    cout << "nth term: " << prog.getNthTerm(5) << endl;
    cout << "sum: " << prog.getSumOfTerms(5) << endl;
    return 0;
}
