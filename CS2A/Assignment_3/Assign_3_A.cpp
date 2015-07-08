#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// main client --------------------------------------------------------
int main()
{
   // food #1 constants
   const string FOOD_1_NAME = "avocado";
   const  int FOOD_1_CALORIES_P100G = 160;  // in calories
   const  double FOOD_1_SOL_FIBER_P100G = 1.75;   // in grams
   const double FOOD_1_SATURATED_FAT_P1OOG = ; // in grams
   const double FOOD_1_SUGARS_P100g = ; // in grams

   /// food #2 constants
   const string FOOD_2_NAME = "avocado";
   const  int FOOD_2_CALORIES_P100G = 160;  // in calories
   const  double FOOD_2_SOL_FIBER_P100G = 1.75;   // in grams
   const double FOOD_2_SATURATED_FAT_P1OOG = ; // in grams
   const double FOOD_2_SUGARS_P100g = ; // in grams

   /// food #3 constants
   const string FOOD_3_NAME = "avocado";
   const  int FOOD_3_CALORIES_P100G = 160;  // in calories
   const  double FOOD_3_SOL_FIBER_P100G = 1.75;   // in grams
   const double FOOD_3_SATURATED_FAT_P1OOG = ; // in grams
   const double FOOD_3_SUGARS_P100g = ; // in grams

   // food #4 constants
   const string FOOD_4_NAME = "avocado";
   const  int FOOD_4_CALORIES_P100G = 160;  // in calories
   const  double FOOD_4_SOL_FIBER_P100G = 1.75;   // in grams
   const double FOOD_4_SATURATED_FAT_P1OOG = ; // in grams
   const double FOOD_4_SUGARS_P100g = ; // in grams

   // food #5 constants
   const string FOOD_5_NAME = "avocado";
   const  int FOOD_5_CALORIES_P100G = 160;  // in calories
   const  double FOOD_5_SOL_FIBER_P100G = 1.75;   // in grams
   const double FOOD_5_SATURATED_FAT_P1OOG = ; // in grams
   const double FOOD_5_SUGARS_P100g = ; // in grams
 
   const  string INDENT = "   ";

   // Define User Input Variables
   string recipeName, userInputStr;
   int userInputInt;
   int totalCals;
   double totalSolFiber, totalSatFat, totalSugars;

   // initialize accumulator variables
   totalSolFiber  = 0.;
   totalCals =  0;
   totalSatFat = 0;
   totalSugars = 0;

   // print menu
   cout << "---------- List of Possible Ingredients ---------" << endl;
   cout << INDENT << "Food #1: " << FOOD_1_NAME << endl;
   cout << INDENT << "Food #2: " << FOOD_2_NAME << endl;
   cout << INDENT << "Food #3: " << FOOD_3_NAME << endl;    
   cout << INDENT << "Food #4: " << FOOD_4_NAME << endl;    
   cout << INDENT << "Food #5: " << FOOD_5_NAME << endl;    

   // name of recipe
   cout << "What are you calling this recipe? ";
   getline(cin, recipeName);

   // food #1 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_1_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt; 

   // update accumulators
   totalCals += userInputInt * (FOOD_1_CALORIES_P100G/100.);
   totalSolFiber  += userInputInt * (FOOD_1_SOL_FIBER_P100G/100.);

   // food #2 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_2_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;

   // update accumulators
   totalCals += userInputInt * (FOOD_2_CALORIES_P100G/100.);
   totalSolFiber  += userInputInt * (FOOD_2_SOL_FIBER_P100G/100.);

   // food #3 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_3_NAME << "? ";
   getline(cin, userInputStr);
   istringstream(userInputStr) >> userInputInt;

   // update accumulators
   totalCals += userInputInt * (FOOD_3_CALORIES_P100G/100.);
   totalSolFiber  += userInputInt * (FOOD_3_SOL_FIBER_P100G/100.);   

   // report results --------------------------------------------------
   cout << "\nNutrition for " << recipeName << "------------" << endl; 
   cout << INDENT << "Calories: " << totalCals << endl;
   cout << INDENT << "Soluble Fiber: " << totalSolFiber << endl;

   return 0;
}
