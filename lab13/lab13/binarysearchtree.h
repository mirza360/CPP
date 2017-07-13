#pragma once
#include<iostream>
#include<queue>
#include<algorithm>
template <class ItemType>
struct TreeNode {
	ItemType info;
	TreeNode *left;
	TreeNode *right;
};
enum Ordertype {PRE_ORDER, IN_ORDER,POST_ORDER};
template <class ItemType>
class TreeType
{
public:
	TreeType();
	~TreeType();
	void MakeEmpty();
	bool IsEmpty();
	bool IsFool();
	int lengthIs();
	void RetrieveItem(ItemType& item, bool& found);
	void InsertItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetTree(OrderType order);
	void GetNextItem(ItemType& item, Ordertype order, bool& finished);
	void print();
private:
	TreeNode<ItemType> *root;
	QueueType<ItemType> preQueue;
	QueueType<ItemType> inQueue;
	QueType<ItemType> postQueue;
};

