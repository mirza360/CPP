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
int main()
{

    return 0;
}
Node* TreeInsert(Node*tree, int v) {
	if (tree == NULL) {
		Node*n = new Node();
		n->value = v;
		n->left = NULL;
		n->right = NULL;
	}
	else {
		if (tree->value >= v) {
			tree->right = TreeInsert(tree->right, v);
		}
		else {
			tree->left = TreeInsert(tree->left, v);
		}
	}
	return tree;
}

