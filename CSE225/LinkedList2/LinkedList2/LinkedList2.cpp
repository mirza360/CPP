// LinkedList2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct Node
{
	int value;
	Node *next=NULL;
	Node *prev=NULL;
};
void reverseSingly();
void addNodeToEnd(Node *n);
void insertAtPosition(Node *n, int pos);
void deleteFromPosition(int pos);
void printNode();
Node * head = NULL;
void main()
{
	int idx=0;
	while (idx != 6) {
			cout << "Press 1: Add to the End"<<endl<<"Press 2: Insert at a position"<<endl;
			cout << "Press 3: Delete from a position" << endl << "Press 4: Print" << endl;
			cout << "Press 5: Reverse Considering Singly" << endl <<"Press 6: Terminate" << endl;
		cin >> idx;
		switch (idx) {
		case 1: {
			cout << "Enter Your Value: ";
			int val;
			cin >> val;
			Node *n = new Node;
			n->value = val;
			addNodeToEnd(n);
		}break;
		case 2: {
			cout << "Enter Your Value: ";
			int val;
			cin >> val;
			Node *n = new Node;
			n->value = val;
			cout << "Insert to the position: ";
			int d;
			cin >> d;
			insertAtPosition(n, d);
		}break;
		case 3: {
			cout << "Delete from the position: ";
			int d;
			cin >> d;
			deleteFromPosition(d);
		}break;
		case 4: {
			cout << "Printing the Values" << endl;
			printNode();
		}break;
		case 5: {
			reverseSingly();
		}break;
		case 6: {
			cout << "Terminating!" << endl;
		}break;
		}
	}
	//*/
}


void reverseSingly()
{
	Node *tmpHead = head;
	Node *tmpList = NULL;
	while (tmpHead != NULL) {
		if (tmpList == NULL) {
			tmpList = tmpHead;
			tmpHead = tmpHead->next;
			tmpList->next = NULL;
		}
		else {
			Node *tmp = tmpHead;
			tmpHead = tmpHead->next;
			tmp ->next= tmpList;
			tmpList = tmp;
			
		}
	}
	head = tmpList;
	cout << "Reversed the Node considering it to be a singly"<<endl;
}

void addNodeToEnd(Node * n)
{
	if (head == NULL) {
		head = n;
	}
	else {
		Node *tmpHead = head;
		while (true) {
			if (tmpHead->next == NULL) {
				tmpHead->next = n;
				n->prev = tmpHead;
				break;
			}
			else {
				tmpHead = tmpHead->next;
			}
		}
	}
}

void insertAtPosition(Node * n, int pos)
{	
	int v = n->value;
	Node *tmpHead = head;
	int idx = 1;
	while (idx<pos-1) {
		tmpHead = tmpHead->next;
		idx++;
	}
	n->prev = tmpHead;
	n->next = tmpHead->next;
	tmpHead->next->prev = n;
	tmpHead->next = n;
	cout << "Successfully Inserted " << v << " at the #" << pos << " Position!" << endl;
}

void deleteFromPosition(int pos)
{
	Node *tmpHead = head;
	int idx = 1;
	while (idx<pos) {
		tmpHead = tmpHead->next;
		idx++;
	}
	if (tmpHead->next == NULL) {
		tmpHead->prev->next = NULL;
		cout << tmpHead->value << "Is been deleted" << endl;
		delete tmpHead;
	}
	else {
		tmpHead->prev->next = tmpHead->next;
		tmpHead->next->prev = tmpHead->prev;
		cout << tmpHead->value << "Is been deleted" << endl;
		delete tmpHead;
	}	
}

void printNode()
{
	Node *tmpHead=head;
	if (tmpHead == NULL) {
		cout << "Nothing" << endl;
	}
	else {
		while (tmpHead != NULL) {
			cout << tmpHead->value << " ";
			tmpHead = tmpHead->next;
		}
		cout << endl;
	}
}

