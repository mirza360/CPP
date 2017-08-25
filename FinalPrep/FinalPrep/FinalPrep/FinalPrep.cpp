// FinalPrep.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct BST {
	int value;
	BST* left=NULL;
	BST* right=NULL;
};
BST* insert(BST* root, int val);
int main()
{
    return 0;
}

BST * insert(BST * root, int val)
{
	if (root == NULL) {
		BST* tmp = new BST;
		tmp->value=val;
	}
	else {
		BST *target = new BST;
		target->value = val;
		BST*tmp = root;
		BST*preTemp = root;
		while (tmp) {
			if (val >= tmp->value) {
				preTemp = tmp;
				tmp = tmp->right;
			}
			else {
				preTemp = tmp;
				tmp = tmp->left;
			}
		}
		if (preTemp->value >= val) {
			preTemp->right = target;
		}
		else {
			preTemp->left = target;
		}
	}
	return root;
}
