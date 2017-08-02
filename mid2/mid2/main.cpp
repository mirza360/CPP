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
int findWidth(Node *tree);
//int greatNonNeg(Node *tree);
int main()
{
	root = TreeInsert(root, 55);
	root = TreeInsert(root, 44);
	root = TreeInsert(root, 22);
	root = TreeInsert(root, 33);
	root = TreeInsert(root, 66);
	root = TreeInsert(root, 77);
	root = TreeInsert(root, 88);
	root = TreeInsert(root, 99);
	root = TreeInsert(root, 11);
	print(root);
	cout << endl;
	//printOdds(root);
	int x = 0;
	x=printOdds(root);
	cout << x<<endl;
	cout << findWidth(root);

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
int findWidth(Node *tree) {
	if (tree == NULL) {
		return 0;
	}
	else {
		int x = 0;
		Node*tmp = tree;
		while (tmp) {
			x++;
			tmp = tmp->left;
			
		}
		tmp = tree;
		while (tmp) {
			x++;
			tmp = tmp->right;
			
		}
		return x;
	}
}
/*
int greatNonNeg(Node *tree) {
	if (tree == NULL) {
		return 0;
	}
	else {
		int x = 0;
		if (tree->value > 0) {
			x = tree->value;
		}
		else {
			Node*tmp = tree;
			bool checker = false;
			while (tmp) {

				tmp = tmp->left;
				if (tmp->value > 0) {
					x = tmp->value;
					break;
				}
				else {
					Node *t2 = tmp;
					while (t2) {
						t2 = t2->right;
						if (t2->value > 0) {
							x = t2->value;
							break;
						}
					}
				}
			}
		}
	}
}
*/