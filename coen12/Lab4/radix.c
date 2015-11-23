// Name: Deen Aariff
// Student ID: W1103023
// Assignment: #4 Maze and Radix 
// Class: COEN 12L T 2:15-5:00
// Date: 11/08/15

#include"deque.h"
#include<assert.h>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

struct node {
	int data;
	struct node* prev;
	struct node* next;
};

struct deque {
	int count;
	struct node* dummy;
};

typedef struct node NODE;

// Algorithmic Complexity: O(n)
int main () {
	static int const RADIX = 10;
	DEQUE *array[RADIX + 1]; // first element of array is main deque 
	for (int i = 0; i < RADIX + 1; i++) {
		array[i] = createDeque(); // allocate memory for each deque 
	}
	int val = 0;
	int maxDigits = 1;
	printf("Please Enter Positive Integer Values: \n");
	while (scanf("%d", &val) == 1) { // read for values
		assert(val >= 0); // can't sort negative values
		int digits = ceil(log(val+1)); // number of digits
		if (digits > maxDigits) { // set new highest number of digits
			maxDigits = digits;
		}
		addLast(array[0],val); // Add value to the main deque
	}	
	for (int j = 0; j < maxDigits; j++) { // Repeat for number of sorts required
		int arraySize = numItems(array[0]);
		for (int k = 0; k < arraySize; k++) { // Iterate through list of numbres
			int elt = removeFirst(array[0]); // remove First element and store value
			int bin = (elt/(int)pow(10,j) % 10); // find value of j digit
			addLast(array[bin+1], elt); // Add element to appropriate bin
		}
		for (int l = 1; l < RADIX + 1; l++) { // Iterate through all bins
			int binSize = numItems(array[l]);
			for (int m = 0; m < binSize; m++) { // deterine nuber of items in bin
				int elt = removeFirst(array[l]);
				addLast(array[0], elt); // put all values from bin into item array
			}
		}
	}
	printf("All Values Sorted: ");
	int size = numItems(array[0]);
	for (int k = 0; k < size; k++) { // Iterate through list of numbres
		int val = removeFirst(array[0]); 
		printf(" %d ",val); // Print all values 
	}
	printf("\n");
	return 0;;
}