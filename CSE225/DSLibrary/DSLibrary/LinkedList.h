#pragma once
#include<iostream>

using namespace std;
//Linked List Node

struct LinkNode {
	int value;
	LinkNode *next;
	LinkNode *prev;
};


class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	LinkNode* insert(LinkNode *n);
private:
	
	LinkNode *root;
};

