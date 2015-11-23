// Name: Deen Aariff
// Student ID: W1103023
// Assignment: #5 Heap & Huffman
// Class: COEN 12L T 2:15-5:00
// Date: 11/22/15

#include"tree.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

// tree data type
struct tree {
 	struct tree *parent;
 	struct tree *left;
 	struct tree *right;
 	int data;
 };

// Determines which side of parent tree is on
// sets to null
// O(1)
void freeChild (struct tree *root) {
	if (root -> parent == NULL) {
		return;
	}
	// if node of another tree set to null in that tree
	if (root -> parent -> right == root)
		root -> parent -> right = NULL;
	else if (root -> parent -> left == root)
		root -> parent -> left = NULL;
}

// Intializes tree with data, left node, right node
// O(1)
struct tree* createTree(int data, struct tree* left, struct tree* right) {
	struct tree *root;
	// allocate memory
	root = malloc(sizeof(struct tree));
	assert (root != NULL);

	// intializes data
	root -> data = data;
	root -> left = left;
	root -> right = right;
	root -> parent = NULL;
	// ensure left is not element of another tree
	if (left != NULL)
	{
		freeChild(left);
		left -> parent = root;
	}
	// ensure righ tis not element of anotehr tree
	if (root -> right != NULL)
	{
		freeChild(right);
		right -> parent = root;
	}
	return (root);
};

// destroys Tree
// O(n)
void destroyTree(struct tree *root) {
	// recursive call until right and left are both null
	if (root->right != NULL)
		destroyTree(root->right);
	if (root->left != NULL)
		destroyTree(root->left);
	// free root
	free (root);
};

// Returns data of Tree
// O(1)
int getData(struct tree *root) {
	assert (root != NULL);
	return root->data;
};

// returns left node of Tree
// O(1)
struct tree* getLeft(struct tree *root){
	assert (root != NULL);
	return root->left;
};

// returns right node of Tree
// O(1)
struct tree* getRight(struct tree *root) {
	assert (root != NULL);
	return root->right;
};

// returns parent of Tree
// O(1)
struct tree* getParent(struct tree *root) {
	assert(root != NULL);
	return root->parent;
};

// Sets left node of Tree
// O(1)
void setLeft(struct tree *root, struct tree *left) {
	if (left == NULL) {
		root -> left = NULL;
		return;
	}
	// if not null ensure not part of another tree
	if (root -> left != NULL) {
		freeChild (left);
	}
	// set pointers
	root -> left = left;
	left -> parent = root;
	return;

};

// Sets right node of Tree
// O(1)
void setRight(struct tree *root, struct tree *right) {
	if (right == NULL) {
		root -> right = NULL;
		return;
	}
	// if not null ensure not part of anotehr tree
	if (root -> right != NULL) {
		freeChild (right);
	}
	// set pointers
	root -> right = right;
	right -> parent = root;
	return;
};
