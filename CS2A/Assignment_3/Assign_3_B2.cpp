#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    // define names of ingredients and nutrients
    string ingredients [] = {"Cowpeas"};
    string nutrients [] = {"Calories", "Fiber", "Sugars", "Saturated Fat"};
    // array for amount of each ingredient
    int amount [5];
    // nutrition values for nutrition types (index correspond to ingredient)
    const double NUTRITION [][sizeof(ingredients)] = {
        {200}, // Calories 
        {11.2}, // Fiber
        {5.7}, // Sugars
        {0.2}, // Saturated Fat
    };
    // totals of each nutrition element
    int totals [5];
    // populate amounts (n) 
    for (int i=0; i <= sizeof(ingredients); i++) {
         cout << "How many grams of: " << ingredients[i] << "?\n";	 
         cin>>amount[i];
         cin.ignore();
    }
    // populate total (n^2)  
    for (int i=0; i <= sizeof(nutrients); i++) {
         for (int j =0; i <= sizeof(ingredients); j++) {
              totals[i] = totals[i] + NUTRITION[i][j] * amount[j];
         }
    } 
    // table headers
    // cout << "Nutrition for " << recipeName << "----------------\n";
    // print ingredient totals (n)
    for (int i = 0; i < sizeof(nutrients); i++) {
	cout << nutrients[i] << ":" << totals[i];
    }
}
