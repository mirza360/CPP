// mid2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;
struct Node {
	int value;
	Node *left;
	Node *right;
};
Node *root = NULL;
Node* TreeInsert(Node*tree, int v);
void print(Node*tree);
int printOdds(Node *tree);
int main()
{
	root = TreeInsert(root, 55);
	root = TreeInsert(root, 11);
	root = TreeInsert(root, 22);
	root = TreeInsert(root, 33);
	root = TreeInsert(root, 44);
	root = TreeInsert(root, 66);
	root = TreeInsert(root, 77);
	root = TreeInsert(root, 88);
	root = TreeInsert(root, 99);
	print(root);
	cout << endl;
	//printOdds(root);
	int x = 0;
	x=printOdds(root);
	cout << x;

	return 0;
}
Node* TreeInsert(Node*tree, int v) {
	if (tree == NULL) {
		Node*n = new Node();
		n->value = v;
		n->left = NULL;
		n->right = NULL;
		tree = n;
		//cout << "HELLO";
	}
	else {
		if (tree->value >= v) {
			tree->left = TreeInsert(tree->left, v);
		}
		else {
			tree->right = TreeInsert(tree->right, v);
		}
	}
	return tree;
}

void print(Node*tree) {
	if (tree == NULL) {
		//cout << "No Value";
	}
	else {
		print(tree->left);
		cout << tree -> value<<" ";
		print(tree->right);

	}
}
int printOdds(Node *tree) {
	int ret = 0;
	if (tree) {
		
		if (tree->value % 2 == 1) {
			ret= 1;
		}
		else {
			ret= 0;
		}
		//printOdds(tree->right);
		return ret + printOdds(tree->left) + printOdds(tree->right);
	}
	else {
		return 0;
	}
	
	
}