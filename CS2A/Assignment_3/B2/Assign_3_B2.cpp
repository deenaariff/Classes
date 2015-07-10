#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//edits

int main() {
    // define names of ingredients and nutrients
    string ingredients [] = {"Cowpeas","Cinnamon","Salt","Goat Cheese"};
    string nutrients [] = {"Calories", "Fiber", "Sugars", "Saturated Fat"};
    // array for amount of each ingredient and totals of each nutrition element
    int amount [5];
    int totals [5];
    // nutrition values for nutrition types (index correspond to ingredient)
    const double NUTRITION [][sizeof(ingredients)] = {
        {200,100,30,30}, // Calories 
        {11.2,22.2,30.4,20.4}, // Fiber
        {5.7,3.4,5.5,4.4}, // Sugars
        {0.2,3.4,3.3,4.4}, // Saturated Fat
    };
    for (int i=0; i < 4; i++) {
	cout << i;
    }
    // populate amounts (n) 
    for (int i=0; i < 2; i++) {
	 cout << i << "\n";
         cout << "How many grams of: " << ingredients[i] << "?\n";	 
         cin>>amount[i];
	 cout<<"Just added to amount[i] " << "where I is: " << i << "and Amount of i: " << amount[i] << "\n";
	 cout<<"Array index + 1: " << amount[i+1] << "\n";
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
    return 0;
}
