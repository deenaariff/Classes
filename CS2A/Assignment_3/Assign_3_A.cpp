#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// main client --------------------------------------------------------
int main()
{
   // food #1 constants
   const string FOOD_1_NAME = "raw avocado";
   const int FOOD_1_PROTEIN_P100G = 2.0;  // in protein
   const double FOOD_1_SOL_FIBER_P100G = 7.0;  // in grams
   const double FOOD_1_SAT_FAT_P100G = 2.0; // in grams
   const double FOOD_1_SUGARS_P100G = 1.0; // in grams

   /// food #2 constants
   const string FOOD_2_NAME = "garbanzo beans";
   const int FOOD_2_PROTEIN_P100G = 5.0;  // in protein
   const double FOOD_2_SOL_FIBER_P100G = 4.0;  // in grams
   const double FOOD_2_SAT_FAT_P100G = 0.0; // in grams
   const double FOOD_2_SUGARS_P100G = 0.0; // in grams

   /// food #3 constants
   const string FOOD_3_NAME = "cinnamon";
   const int FOOD_3_PROTEIN_P100G = 4.0;  // in protein
   const double FOOD_3_SOL_FIBER_P100G = 53.0;   // in grams
   const double FOOD_3_SAT_FAT_P100G = 0.0; // in grams
   const double FOOD_3_SUGARS_P100G = 2.0; // in grams

   // food #4 constants
   const string FOOD_4_NAME = "banana";
   const int FOOD_4_PROTEIN_P100G = 1.0;  // in protein
   const double FOOD_4_SOL_FIBER_P100G = 3.0;   // in grams
   const double FOOD_4_SAT_FAT_P100G = 0.0; // in grams
   const double FOOD_4_SUGARS_P100G = 12.0; // in grams

   // food #5 constants
   const string FOOD_5_NAME = "strawberries";
   const  int FOOD_5_PROTEIN_P100G = 1.0;  // in protein
   const  double FOOD_5_SOL_FIBER_P100G = 3.0;   // in grams
   const double FOOD_5_SAT_FAT_P100G = 0.0; // in grams
   const double FOOD_5_SUGARS_P100G = 7.0; // in grams
 
   const  string INDENT = "   ";

   // Define User Input Variables
   string recipeName, userInputStr;
   int userInputInt;
   double totalProtein, totalSolFiber, totalSatFat, totalSugars;

   // initialize accumulator variables
   totalSolFiber = 0.0;
   totalProtein =  0.0;
   totalSatFat = 0.0;
   totalSugars = 0.0;

   // print menu
   cout << "---------- List of Possible Ingredients ---------" << endl;
   cout << INDENT << "Food #1: " << FOOD_1_NAME << endl;
   cout << INDENT << "Food #2: " << FOOD_2_NAME << endl;
   cout << INDENT << "Food #3: " << FOOD_3_NAME << endl;    
   cout << INDENT << "Food #4: " << FOOD_4_NAME << endl;    
   cout << INDENT << "Food #5: " << FOOD_5_NAME << endl;    

   // name of recipe
   cout << "What are you calling this recipe? ";
   getline(cin,recipeName);

   // output strings 
   const string ERROR = "ERROR: The input did not fall
   within the desired paramaters ";
   const string AMOUNT_PARAM = "(Greater than 0 grams and
   less than 1000 grams)";
   const string SERVING_PARAM = "(An Integer Between 1 and 10)";

   // food #1 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_1_NAME << "? " << AMOUNT_PARAM << ": ";
   getline(cin,userInputStr); // get user input
   istringstream(userInputStr) >> userInputInt;
   /// test for paramaters
   if ((userInputInt < 0) || (userInputInt > 1000)) {
	    cout << ERROR;
	   return 0;
   }
 
   // update accumulators
   totalProtein += userInputInt * (FOOD_1_PROTEIN_P100G/100.);
   totalSolFiber += userInputInt * (FOOD_1_SOL_FIBER_P100G/100.);
   totalSatFat += userInputInt * (FOOD_1_SAT_FAT_P100G/100.);
   totalSugars += userInputInt * (FOOD_1_SUGARS_P100G/100.);

   // food #2 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_2_NAME << "? " << AMOUNT_PARAM << ": ";
   getline(cin,userInputStr);
   istringstream(userInputStr) >> userInputInt;
   // test for paramaters
   if ((userInputInt < 0) || (userInputInt > 1000)) {
	    cout << ERROR;
	    return 0;
   }  

   // update accumulators
   totalProtein += userInputInt * (FOOD_2_PROTEIN_P100G/100.);
   totalSolFiber  += userInputInt * (FOOD_2_SOL_FIBER_P100G/100.);
   totalSatFat += userInputInt * (FOOD_2_SAT_FAT_P100G/100.);
   totalSugars += userInputInt * (FOOD_2_SUGARS_P100G/100.);

   // food #3 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_3_NAME << "? " << AMOUNT_PARAM << ": ";
   getline(cin,userInputStr); 
   istringstream(userInputStr) >> userInputInt;
   // test for paramaters
   if ((userInputInt < 0) || (userInputInt > 1000)) {
      cout << ERROR;
      return 0;
   }

   // update accumulators
   totalProtein += userInputInt * (FOOD_3_PROTEIN_P100G/100.);
   totalSolFiber  += userInputInt * (FOOD_3_SOL_FIBER_P100G/100.);
   totalSatFat += userInputInt * (FOOD_3_SAT_FAT_P100G/100.);
   totalSugars += userInputInt * (FOOD_3_SUGARS_P100G/100.);

   // food #4 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_4_NAME << "?  " << AMOUNT_PARAM << ": ";
   getline(cin,userInputStr);   
   istringstream(userInputStr) >> userInputInt;
   // test for paramaters
   if ((userInputInt < 0) || (userInputInt > 1000)) {
      cout << ERROR;
      return 0;
   }

   // update accumulators
   totalProtein += userInputInt * (FOOD_4_PROTEIN_P100G/100.);
   totalSolFiber  += userInputInt * (FOOD_4_SOL_FIBER_P100G/100.);
   totalSatFat += userInputInt * (FOOD_4_SAT_FAT_P100G/100.);
   totalSugars += userInputInt * (FOOD_4_SUGARS_P100G/100.);

   // food #5 ---------------------------------------------------------
   cout << "How many grams of " << FOOD_5_NAME << "? " << AMOUNT_PARAM << ": ";
   getline(cin,userInputStr); 
   istringstream(userInputStr) >> userInputInt;
   // test for paramaters
   if ((userInputInt < 0) || (userInputInt > 1000)) {
      cout << ERROR;
      return 0;
   }

   // update accumulators
   totalProtein += userInputInt * (FOOD_5_PROTEIN_P100G/100.);
   totalSolFiber += userInputInt * (FOOD_5_SOL_FIBER_P100G/100.);
   totalSatFat += userInputInt * (FOOD_5_SAT_FAT_P100G/100.);
   totalSugars += userInputInt * (FOOD_5_SUGARS_P100G/100.);

   // user input serving number

   int servings;
   cout << "How many servings will you prepare " << SERVING_PARAM << ": " ;
   cin >> userInputStr; 
   istringstream(userInputStr) >> servings;
   if ((servings < 1) || (servings > 10)) {
        cout << ERROR;
        return 0;
   }
  
   // per servings totals
   double proteinPerServ = totalProtein / servings; 
   double solFiberPerServ = totalSolFiber / servings;
   double satFatPerServ = totalSatFat / servings;
   double sugarsPerServ = totalSugars / servings;

   // report results --------------------------------------------------
   cout << "\nNutrition for " << recipeName << "------------" << endl; 
   cout << INDENT << "Protein: " << proteinPerServ << " grams" << endl;
   cout << INDENT << "Soluble Fiber: " << solFiberPerServ << " grams" <<endl;
   cout << INDENT << "Saturated Fat: " << satFatPerServ << " grams" << endl;
   cout << INDENT << "Sugars: " << sugarsPerServ << " grams" << endl;
 
   return 0;
}

/*---------------------  RUN 1 --------------------------

 ---------- List of Possible Ingredients ---------
 Food #1: raw avocado
 Food #2: garbanzo beans
 Food #3: cinnamon
 Food #4: banana
 Food #5: strawberries
 What are you calling this recipe? Banana Smoothie
 How many grams of raw avocado? (Greater than 0 grams and less than 1000 grams): 5
 How many grams of garbanzo beans? (Greater than 0 grams and less than 1000 grams): 5
 How many grams of cinnamon? (Greater than 0 grams and less than 1000 grams): 5
 How many grams of banana?  (Greater than 0 grams and less than 1000 grams): 30
 How many grams of strawberries? (Greater than 0 grams and less than 1000 grams): 5
 How many servings will you prepare (An Integer Between 1 and 10): 1

 Nutrition for Banana Smoothie------------
 Protein: 0.9 grams
 Soluble Fiber: 4.25 grams
 Saturated Fat: 0.1 grams
 Sugars: 4.1 grams


------------------------ RUN 2 ----------------------------
 
 ---------- List of Possible Ingredients ---------
 Food #1: raw avocado
 Food #2: garbanzo beans
 Food #3: cinnamon
 Food #4: banana
 Food #5: strawberries
 What are you calling this recipe? Cinnamon Swirl Smoothie
 How many grams of raw avocado? (Greater than 0 grams and less than 1000 grams): 0
 How many grams of garbanzo beans? (Greater than 0 grams and less than 1000 grams): 10
 How many grams of cinnamon? (Greater than 0 grams and less than 1000 grams): 10
 How many grams of banana?  (Greater than 0 grams and less than 1000 grams): 20
 How many grams of strawberries? (Greater than 0 grams and less than 1000 grams): 20
 How many servings will you prepare (An Integer Between 1 and 10): 3

 Nutrition for Cinnamon Swirl Smoothie------------
 Protein: 0.433333 grams
 Soluble Fiber: 2.3 grams
 Saturated Fat: 0 grams
 Sugars: 1.33333 grams


------------------------ RUN 3 ----------------------------

 --------- List of Possible Ingredients ---------
 Food #1: raw avocado
 Food #2: garbanzo beans
 Food #3: cinnamon
 Food #4: banana
 Food #5: strawberries
 What are you calling this recipe? Banana Strawberry Breeze
 How many grams of raw avocado? (Greater than 0 grams and less than 1000 grams): 0
 How many grams of garbanzo beans? (Greater than 0 grams and less than 1000 grams): 0
 How many grams of cinnamon? (Greater than 0 grams and less than 1000 grams): 0
 How many grams of banana?  (Greater than 0 grams and less than 1000 grams): 30
 How many grams of strawberries? (Greater than 0 grams and less than 1000 grams): 30
 How many servings will you prepare (An Integer Between 1 and 10): 2

 Nutrition for Banana Strawberry Breeze------------
 Protein: 0.3 grams
 Soluble Fiber: 0.9 grams
 Saturated Fat: 0 grams
 Sugars: 2.85 grams

------------------------ RUN 4 ----------------------------

 ---------- List of Possible Ingredients ---------
 Food #1: raw avocado
 Food #2: garbanzo beans
 Food #3: cinnamon
 Food #4: banana
 Food #5: strawberries
 What are you calling this recipe? Dud Recipe
 How many grams of raw avocado? (Greater than 0 grams and less than 1000 grams): 0
 How many grams of garbanzo beans? (Greater than 0 grams and less than 1000 grams): 101
 How many grams of cinnamon? (Greater than 0 grams and less than 1000 grams): 2000
 ERROR: The input did not fall within the desired paramaters


------------------------ RUN 5 ----------------------------

 ---------- List of Possible Ingredients ---------
 Food #1: raw avocado
 Food #2: garbanzo beans
 Food #3: cinnamon
 Food #4: banana
 Food #5: strawberries
 What are you calling this recipe? Deen's Specialty
 How many grams of raw avocado? (Greater than 0 grams and less than 1000 grams): 20
 How many grams of garbanzo beans? (Greater than 0 grams and less than 1000 grams): 30
 How many grams of cinnamon? (Greater than 0 grams and less than 1000 grams): 30
 How many grams of banana?  (Greater than 0 grams and less than 1000 grams): 30
 How many grams of strawberries? (Greater than 0 grams and less than 1000 grams): 30
 How many servings will you prepare (An Integer Between 1 and 10): 20
 ERROR: The input did not fall within the desired paramaters

 ---------------------------------------------------------*/


