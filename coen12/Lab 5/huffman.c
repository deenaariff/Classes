// Name: Deen Aariff
// Student ID: W1103023
// Assignment: #5 Heap & Huffman
// Class: COEN 12L T 2:15-5:00
// Date: 11/22/15

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "assert.h"
#include "pack.h"
#include <ctype.h>

int heapCount;

struct tree {
    struct tree *parent;
    struct tree *left;
    struct tree *right;
    int data;
 };

typedef struct tree TREE;

// Function for tree traversal through array
#define p(x) (((x)-1)/2)
#define l(x) (((x)*2)+1)
#define r(x) (((x)*2)+2)

// Insert Tree into heap 
void insert (TREE *array[], TREE *elt) {
    // insert tree into end of heap 
	array[heapCount] = elt; 
    // make index equal heapCount
    int indexCur = heapCount;
    // index parent of heapCount
    int indexPar = p(heapCount);
    // while data parent is greater than current eindex
    while((indexCur != 0) && ((array[indexCur])->data < (array[indexPar])->data)) {
        // temp stores current value
        TREE *temp = array[indexCur];
        // make current equals parent
        array[indexCur] = array[indexPar]; 
        // parent quals temp
        array[indexPar] = temp;
        // update current index
        indexCur = indexPar; 
        indexPar = p(heapCount);
    };
    // increment heapCount 
    heapCount++;
}

// Remove min value
// traverse last value down heap from index of 0
TREE* delete (TREE *array[]) {
    int index = 0;
    int child = 0;
    // store first value in heapCount
    TREE *root = array[0];
    /// store last val
    TREE *lastVal = array[--heapCount];
    // not at beggining of heap 
    while (l(index) < heapCount) {
        // child index equals left index
        child = l(index);
        // if left data greater than right traverse right
        if ((array[l(index)])->data > (array[r(index)])->data) 
            child = r(index);
        // original last val is less than new child than traverse down
        if ((lastVal)-> data > array[child]->data) {
            array[index] = array[child];
            index = child;
        }   
        else 
            break;
        // update index to child 
        index = child; 
    }
    // store val equals traversed index
    array[index] = lastVal;
    // return first value
    return root; 
}

// Print code given node
void binary (TREE *node) {
    // if parent is null return
    if (node -> parent == NULL)
        return;      
    // recursive call to parent
    binary(node -> parent);
    // if left node then print 1
    if (getLeft(node -> parent) == node)
        printf("0");
    // if right node then print 0
    else 
        printf("1");
}


int main (int argc, char** argv) {
	FILE *fp; // define pointer fp of type FILE
    int count [257]; // store count values
	TREE* leaves [257]; // store leaves
	TREE* heap [257]; // heap array
	heapCount = 0; // heapCount = 0
    // initialize all arrays
    for (int i = 0; i < 257; i++) {
        count[i] = 0;
        heap[i] = NULL;
        leaves[i] = NULL;
    }
    // check for correct number of arguments
	if (argc != 3) {
		printf("Incorrect number of arguments");
        return 0;
	}
	// Assigns fp to file passed from argument, passes ERROR if files doesn't exit
    if(!(fp = fopen(argv[1], "r"))) {
        printf("ERROR: file not found \n");
        exit(1);
    }
    // Loop Terminates at end of file
    // increments counter per word scanned using fscanf
    int c;
    while((c=getc(fp))!=EOF) {
        count[c]++;
    }   
    // create Tree for each count greater than 0
    for (int i = 0; i < 257; i++) {
    	if (count[i] > 0) {
            leaves[i] = createTree(count[i], NULL, NULL);
            assert(leaves[i] != NULL);
    	}
    }
    // make EOF root 
    count[256] = 0;
    leaves[256] = createTree(0,NULL,NULL);
    // Insert Values Into Heap
    for (int i = 0; i < 257; i++) {
        if (leaves[i] != NULL)
            insert(heap, leaves[i]);
    }	
    // Combine Trees until heapCount is 1
    while (heapCount > 1) {
        // Remove first two trees in heap
        TREE *remove1 = delete(heap);
        TREE *remove2 = delete(heap);
        int combinedData = remove1 -> data + remove2 -> data; 
        // combine tres
        TREE *newTree = createTree(combinedData, remove1, remove2);
        // insert combined tree into heap
        insert(heap, newTree);
    };

    // Use binary to print out values from heap 
    for (int i = 0; i < 257; i++) { 
        if (leaves[i] != NULL) {
            // if value can be printed
            if (isprint(i)) {
                printf ("'%c': ", i);
                printf ("%d ", count[i]);
                binary(leaves[i]);
                printf ("\n");
            }
            // if value cannot be printed
            else {
                printf ("%o: ", i);
                printf ("%d ", count[i]);
                binary(leaves[i]);
                printf ("\n");
            }     
        }
    }

    // run pack from arguments
    pack (argv[1],argv[2],leaves);

    // free memory from count and leaves
    for (int i = 0; i < 257; i++) {
        // if count does equal 0 destory leaves[i]
        if (count[i] != 0) 
            destroyTree(leaves[i]);
    }

    destroyTree(leaves[256]);

    // close file 
    fclose(fp);
    return 0;
}
