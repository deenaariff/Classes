// Name: Deen Aariff
// Student ID:
// Assignment: #2 Sets and Arrays
// Class: COEN 12L 2:15-5:00
// Date: 10/11/2015

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "set.h"
#include<string.h>
#include<assert.h>

// defining set data components
struct set {
	int count;
	int len;
	char **words;
};

// create the structure
SET *createSet(int maxELTS) {
	SET *sp;
	// allocate size of data structure
	sp = malloc(sizeof(SET));
	// alloc memory space for sp ->words
	sp -> words = malloc(maxELTS*sizeof(char *));
	// initialize len and count
	sp -> len = maxELTS;
	sp -> count = 0;
	return sp;
}

// destroy the set
void destroySet (SET *sp) {
	// check if sp is null 
	assert(sp != NULL);
	// free all indexes of sp->words
	for (int i = 0; i < sp -> count; i++) {
		assert(sp->words[i] != NULL);
		free(sp->words[i]);
	}
	// check if sp->words is null
	assert(sp->words != NULL);
	free(sp->words); // free sp->words
	free(sp); // free sp
}

// Return index if element is found
// Return idnex where element should be found
static int findElement (SET *sp, char *elt, bool *found)
{ 
    // initialize low, middle, and high
    int low = 0;
    int high = sp->count-1;
    int middle = (high+low)/2;
    // while loop terminates if low is greater than high
    while (low <= high) {
	// strings are equal
	if (strcmp(elt,sp->words[middle]) == 0) {
           *found = true; // has element, found is true
	    return middle; // return middle
	}
	// element is below middle value
        else if (strcmp(elt, sp->words[middle]) < 0) { 
            high = middle-1; // lower high to below middle
	    middle = (high+low)/2;
        }
	// element is above middle value
        else if (strcmp(elt,sp->words[middle]) > 0) {
	    low = middle+1; // increase low to above middle
	    middle = (high+low)/2;
	}
    }
    *found = false; // element not found, found is false
    return low; // return low value
}

// Return number of elements (count) in set
int numElements (SET *sp) {
	return sp -> count;
}

// returns true if element is present
bool hasElement (SET *sp, char *elt) {
	bool found;
	// pass found by reference
	int index = findElement(sp, elt, &found);
	return found;
}

// add element in correct ordered location
bool addElement (SET *sp, char *elt) { 
    // checks if empty set
    assert (sp->len != 0 || sp != NULL);
    // determine max number of elements
    if (sp -> count == sp -> len) {
        return false;
    }
    bool f; 
    // pass f by reference
    int index = findElement (sp, elt, &f);
    if (f == true) {
	return false;
    }
    elt = strdup(elt); // allocate memory for string from buffer paramater
    // shift elements beyond added element right one index
    for (int i = (sp->count-1); i >= index; i--)
        sp->words[i+1]= sp->words[i]; 
    sp -> words[index] = elt; // insert element into set
    sp -> count++; // increment counter
    return true;
}

// remove Element in set
bool removeElement (SET *sp, char *elt) {
	// if element is not present then return false
	if (hasElement(sp, elt) == false)
		return false;
	bool found; // value to allow findElement() to be called
	// get index value 
	int index = findElement(sp, elt, &found);
	// shift elements into position of element in question
	for (int j = index; j < (sp-> count-1); j++) {
		sp -> words[j] = sp->words[j + 1];
	}
	// set old last value to null to accomodate shift
	sp->words[sp->count-1] = NULL;
	sp->count--; // decrement counter
	return true;
}
