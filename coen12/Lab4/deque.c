// Name: Deen Aariff
// Student ID: W1103023
// Assignment: #4 Maze and Radix 
// Class: COEN 12L T 2:15-5:00
// Date: 11/08/15

#include"deque.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

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

// Create Deque
// Create dummy node that points to null values (prev and next)
// Algorithmic Complexity: O(1)
DEQUE *createDeque(void) {
	DEQUE *dp; // create DEQUE called list
	dp = malloc(sizeof(DEQUE)); // allocated memory for list
	dp -> count = 0; // set count of list to 0
	NODE *blank; // define node called blank
	blank = malloc(sizeof(NODE)); // allocated memory for blank
	dp -> dummy = blank; // set dummy to blank 
	dp -> dummy -> prev = NULL; // give null value to prev 
	dp -> dummy -> next = NULL; // give null value to next
	return dp;
}

// Destory deque and all elements in data structure
// Algorithmic Complexity: O(n)
void destroyDeque(DEQUE *dp) {
	assert(dp != NULL); // Make sure dp is valid deque
	NODE *temp = malloc(sizeof(struct node));
	NODE *next = malloc(sizeof(struct node));
	if (dp->count > 0) { 
		temp = dp->dummy->next; // set pointer dummy to first value
		while (temp != dp->dummy) {  // go through each element
			next = temp->next; // store value of next node
			free(temp); // free node
			temp = next; // set node to next node
		}
	}; 
	free(dp->dummy);
	free(dp); // fre deque 
};

// Return number of items in deque
// Algorithmic Complexity: O(1)
int numItems(DEQUE *dp) {
	return dp->count;
}

// Add new element to front of deque
// Algorithmic Complexity: O(1)
void addFirst(DEQUE *dp, int x) {
	NODE *newFirst; // initialize node to be inserted
	newFirst = malloc(sizeof(struct node)); // allocate memory for node
	assert(newFirst != NULL);
	newFirst -> data = x; // Get data for new First
	newFirst -> prev = dp -> dummy; // new First prev points to dummy
	if (dp->count > 0) {
		NODE *oldFirst = dp-> dummy -> next; // Get node of current first value
		newFirst -> next = oldFirst; // New first next points to current first
		oldFirst -> prev = newFirst; // Old first points back to new first
	}
	else {
		newFirst -> next = dp -> dummy; // point new node to dummy
		dp -> dummy -> prev = newFirst; // point dummy previous to new node
	}
	dp -> dummy -> next = newFirst; // Dummy next points to new first
	dp -> count++; // increment count
};

// Add new element to end of deque
// Algorithmic Complexity: O(1) 
void addLast(DEQUE *dp, int x) {
	NODE *newLast; // initialize node to be inserted
	newLast = malloc(sizeof(struct node)); // allocate memory for node
	assert(newLast != NULL);
	newLast -> data = x; // get data for new Last
	newLast -> next = dp -> dummy; // point newLast next to dummy
	if (dp->count > 0) {
		NODE *oldLast = dp -> dummy -> prev; // Get node of current last value
		oldLast -> next = newLast; // oldLast next points to new Last
		newLast -> prev = oldLast; // New Last prev points back to old last
	}
	else {
		newLast -> prev = dp -> dummy; // point new node last to dummy
		dp -> dummy -> next = newLast; // point dummy next to new node 
	}
	dp -> dummy -> prev = newLast; // dummy prev points to new Last 
	dp -> count ++; // increment count
};

// Remove First element in deque
// Algorithmic Complexity: O(1)
int removeFirst(DEQUE *dp) {
	assert(dp->count != 0); // nothing to remove if no element
	NODE *oldFirst = dp -> dummy -> next; // Get current first node
	int oldData = oldFirst -> data; // Store data of current first node
	if (dp->count > 1) {
		NODE *newFirst = oldFirst -> next; // get node that will be new first
		dp -> dummy -> next = newFirst; // set next of dummy to new first
		newFirst -> prev = dp -> dummy; // new first prev points to dummy
	}
	free(oldFirst); // free old first
	dp -> count--; // decrement count
	return oldData;
}; 

// Remove Last element in deque 
// Algorithmic Complexity: O(1)
int removeLast(DEQUE *dp) {
	assert(dp->count != 0); // nothing to remove if no elemnt
	NODE *oldLast = dp -> dummy -> prev; // Get current last node
	int oldData = oldLast -> data; // store data of current last node
	if (dp->count > 1) {
		NODE *newLast = oldLast -> prev; // Get node that will be new last
		dp -> dummy -> prev = newLast; // Prev of dummy points to new last
		newLast -> next = dp -> dummy; // Next of newLast points to dummy
	}
	free(oldLast); // free old Last
	dp -> count--; // decrement count
	return oldData; // return old last node data
};

// Algorithmic Complexity: O(1)
int getFirst(DEQUE *dp) {
	assert(dp->count != 0); // nothing to return if no elemnt
	return dp->dummy->next->data; // return data in current first node
};

// Algorithmic Complexity: O(1)
int getLast(DEQUE *dp) {
	assert(dp->count != 0); // nothing to return if no elemnt
	return dp->dummy->prev->data; // return data in current last node 
}

// TEST
//int main () {
//	DEQUE * dp = createDeque();
//	addLast(dp, 2);
//	int out = removeFirst(dp);
//	printf("Removed %d\n", out);
//	return out;
//}