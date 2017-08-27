// FinalPrep.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
struct BST {
	int value;
	BST* left=NULL;
	BST* right=NULL;
};
BST* insert(BST* root, int val);
void printInOrder(BST*root);
int findMin(BST* root);
int findHeight(BST* root);
int max(int x, int y);
int findMaxOdd(BST*tree);
int findWidth(BST* tree);
int main()
{
	BST*root = NULL;
	root = insert(root, 10);
	root = insert(root, 7);
	root = insert(root, 8);
	root = insert(root, 6);
	root = insert(root, 9);
	root = insert(root, 12);
	root = insert(root, 11);
	root = insert(root, 13);
	printInOrder(root);
	cout <<"Min Value: " <<findMin(root) << endl;
	cout << "Height :" << findHeight(root)<<endl;
	cout << "Max Odd: " << findMaxOdd(root)<<endl;
	cout << "Find Width: " << findWidth(root) << endl;
	return 0;
}

BST * insert(BST * tree, int val)
{
	if (tree == NULL) {
		BST* tmp = new BST;
		tmp->value=val;
		tree = tmp;
	}
	else if(val>= tree->value) {
		tree->right = insert(tree->right, val);
	}
	else {
		tree->left = insert(tree->left, val);
	}
	return tree;
}
void printInOrder(BST*root) {
	if (root != NULL) {
		printInOrder(root->left);
		cout << root->value<<endl;
		printInOrder(root->right);
	}
}
int findMin(BST* root) {
	BST*tree = root;
	int res;
	if (root != NULL) {
		while (tree) {
			BST*tmp = tree;
			res = tmp->value;
			tree = tree->left;
		}
	}
	return res;

}
int findHeight(BST* tree) {
	if (tree == NULL) {
		return 0;
	}
	else {
		return 1 + max(findHeight(tree->left), findHeight(tree->right));
	}
}
int max(int x, int y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

int findMaxOdd(BST*tree) {
	if (tree != NULL) {
		findMaxOdd(tree->right);
		if (tree->right==NULL && tree->value % 2 == 1) {
			return tree ->value;
			findMaxOdd(NULL);
		}
		else {
			findMaxOdd(tree->left);
		}
		
	}
}
int findWidth(BST* tree) {
	int sum = 1;
	if (tree == NULL) {
		return 0;
	}
	else {
		BST* tmp = tree->left;
		while (tmp) {
			tmp = tmp->left;
			sum++;
		}
		tmp = tree->right;
		while (tmp) {
			tmp = tmp->right;
			sum++;
		}
		
	}
	return sum;
}