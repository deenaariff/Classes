#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "set.h"
#include<string.h>
#include<assert.h>

// define set data structure
struct set {
	int count;
	int len;
	char **words;
};

// create set with paramter of maximum elements
SET *createSet(int maxELTS) {
	SET *sp;
	// allocate size for a set
	sp = malloc(sizeof(SET));
	// allocate memory for sp->words 
	sp -> words = malloc(maxELTS*sizeof(char *));
	// initialize lenght and count
	sp -> len = maxELTS;	
	sp -> count = 0;
	return sp;
}

// destructor for set
void destroySet (SET *sp) {
	// check if sp is null
	assert(sp != NULL);
	// count through each index of sp->words and set to null
	for (int i = 0; i < sp -> count; i++) {
		assert(sp->words[i] != NULL);
		free(sp->words[i]);
	}
	// free sp->words 
	free(sp->words);
	// free sp 
	free(sp);
}

// find Element in set and return index
// indicate not found through bool passed by reference
static int findElement (SET *sp, char *elt, bool *found)
{
	int index = 0;
	*found = false; 
	// sequential search through all elements within set
	for(int i = 0; i < sp -> count; i++) {
		if (strcmp((sp->words[i]), elt)==0)  { // if words is found
			index = i;
			*found = true; // if element found, make bool true
			break; 
		}
	}
	return index;
}

// return number of elements in set
int numElements (SET *sp) {
	return sp -> count;	
}

// return bool whether element is present in set 
bool hasElement (SET *sp, char *elt) {
	bool found;
	// pass found by reference in findElement()
	int index = findElement(sp, elt, &found);
	return found;
}

// Add element to set 
bool addElement (SET *sp, char *elt) {
    assert(sp != NULL || sp->words != 0);
    if (hasElement(sp, elt) == true) {
	return false;
    }
    if (sp -> count > sp -> len) {
	return false;
    }
    elt=strdup(elt);
    sp -> words[sp->count] = elt;
    sp -> count++; 
    return true;
}

// remove Element if in set
bool removeElement (SET *sp, char *elt) {
	// if element not in set, return false
	if (hasElement(sp, elt) == false) 
		return false;
	bool found; // value to enable calliing findElement()
	int index = findElement(sp, elt, &found); // find index value
	assert(sp -> words[index] != NULL); // set sp->words to null	
	// move all elements left into place of removed word 
	for (int j = index; j < sp-> count-1; j++) {
		sp -> words[j] = sp->words[j + 1];
	}
	// set former last elemetn to null to accomodate shift
	if ((sp->count-1) >= 0) {	
		sp->words[sp->count-1] = NULL;
		sp->count--;
	}
	return true;
}

