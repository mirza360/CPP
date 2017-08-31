#include "stdafx.h"
#include "binarysearchtree.h"
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
template <class ItemType>
TreeType<ItemType>::TreeType()
{
	root = NULL;
}
template <class ItemType>
void Destroy(TreeNode<ItemType>*& tree) {
	if (tree != NULL) {
		Destroy(tree->left);
		Destroy(tree->right);
		delete tree;
		tree = NULL;
	}
}
template <class ItemType>
TreeType<ItemType>::~TreeType()
{
	Destroy(root);
}
template <class ItemType>
void TreeType<ItemType>::MakeEmpty() {
	Destroy(root);
}
template <class ItemType>
bool TreeType<Itemtype>::IsEmpty() {
	return root == NULL;
}
template <class ItemType>
bool TreeType<ItemType>::IsFool() {
	TreeNode<ItemType>* location;
	try {
		location = new TreeNode<ItemType>;
		delete location;
		return false;
	}
	catch (bad_alloc& exception) {
		return true;
	}
}
template <class ItemType>
int CountNodes(TreeNode<ItemType>* tree) {
	if (tree == NULL) {
		return 0;
	}
	else {
		return CountNodes(tree->left) + CountNodes(tree->right) + 1;
	}
}
template <class ItemType>
int TreeType<ItemType>::lengthIs() {
	return CountNodes(root);
}
template <class ItemType>
void Retrieve(TreeNode < ItemType*tree, ItemType& item, bool& found) {
	if (tree == NULL) {
		found = false;
	}
	else if (item < tree->info) {
		retrieve(tree->left, item, found);
	}
	else if (item > tree->info) {
		Retrieve(tree->right, item, found);
	}
	else {
		item = tree->info;
		found = true;
	}
}
template <class ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType& item, bool& found) {
	Retrieve(root, item, found);
}
template <class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item) {
	if (tree == NULL) {
		tree = new TreeNode<ItemType>;
		tree->right = NULL;
		tree->left = NULL;
		tree->info = item;
	}else if(item<tree-)
}