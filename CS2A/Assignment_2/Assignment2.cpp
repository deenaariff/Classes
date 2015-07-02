#include <iostream>
#include <math.h> // use pow function
using namespace std;

int main () {
	  //Initialize studID and numLet
  	int studID = 20208433;
  	int numLet = 6;
  	// evaluate answer to questions
  	int eval1 = studID % 2; // value of question 1
  	int eval2 = studID % numLet; // value of question 2
  	int eval3 = studID / numLet; // value of question 3
  	int eval4 = (numLet * (1 + numLet)) / 2; // eval4 calculated using sum of Arithmetic Series (n(a1+an))/2
  	int eval5InParenth = (studID - 54321) / pow ((numLet + 30),2); // parenthesis in denominator
  	int eval5 = 100000 / (99 + eval5InParenth); // value of question 5 
  	// print out values
  	cout << "My last name is Aariff \n";
  	cout << "My Student ID is " << studID << "\n";
  	cout << "The number of characters in my last name is " << numLet << "\n";
  	cout << "Expression #1 ----------: " << eval1 << "\n";
    cout << "Expression #2 ----------: " << eval2 << "\n";
 	  cout << "Expression #3 ----------: " << eval3 << "\n";
    cout << "Expression #4 ----------: " << eval4 << "\n";
    cout << "Expression #5 ----------: " << eval5 << "\n";
}

/*-----------------------------RUN---------------------------------------

My last name is Aariff 
My Student ID is 20208433
The number of characters in my last name is 6
Expression #1 ----------: 1
Expression #2 ----------: 1
Expression #3 ----------: 3368072
Expression #4 ----------: 21
Expression #5 ----------: 6

------------------------------------------------------------------------*/

