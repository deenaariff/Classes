#include <iostream>
#include <time.h>


// Value Object
struct data {
	int value;
};

// NODE DATA STUCTURE
struct node {
	struct data data;
	struct node* left;
	struct node* right;
};

// CREATES NEW NODE
node* NewNode (int data) {
	struct node* node = new(struct node);
    node-> data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// INSERT DATA 
struct node* insert(struct node* node, int data) {
	if (node == NULL)
	    return(NewNode(data));
	else {
	    if (data <= node->data) 
	    	node->left = insert(node->left, data);
	    else 
	    	node -> right = insert(node->right, data);
	     return(node); // returned the (unchanged) pointerj         
	}
}


int basicSol (int index) {
	NewNode (basicSol());
}