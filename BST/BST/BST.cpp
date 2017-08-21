// BST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
struct Node {
	int value;
	Node *left = NULL;
	Node *right = NULL;
};
Node *root = NULL;
Node* insert(int v,Node *root);
void printInOrder(Node*root);
int findHeight(Node *tree);
int maxNum(int x, int y);
void BFS(Node*tree, int val);
//void findGCD(int x);
int main()
{
	root = insert(100 ,root);
	root = insert(50 , root);
	root = insert(30 , root);
	root = insert(75 , root);
	root = insert(200 ,root);
	root = insert(150 , root);
	root = insert(300 , root);
	//printInOrder(root);
	//cout<<findHeight(root);
	//cout<<BFS(root, 50);
	BFS(root, 50);
	BFS(root, 200);
	return 0;
}
Node* insert(int v, Node *tree) {
	
	if (tree == NULL) {
		Node *n = new Node();
		n->value = v;
		tree = n;

	}
	else {
		if (v >= tree->value) {
			tree->right=insert(v, tree->right);
		}
		else {
			tree->left=insert(v, tree->left);
		}
	}
	return tree;
}
void printInOrder(Node*tree) {
	if (tree) {
		printInOrder(tree->left);
		cout << tree->value << endl;
		printInOrder(tree->right);
	}
}
int findHeight(Node *tree) {
	if (tree == NULL) {
		return 0;
	}
	else {
		return 1 + (maxNum(findHeight(tree->left), findHeight(tree->right)));
	}
}
int maxNum(int x, int y) {
	if (x < y) {
		return y;
	}
	else {
		return x;
	}
}
void BFS(Node*tree, int val) {
	//bool check = false;
	if (tree) {
		if (tree->value == val) {
			cout << "Found " << val << endl;
			//check = true;
		}
		else {
			BFS(tree->left,val);
			BFS(tree->right, val);
		}
	}
}