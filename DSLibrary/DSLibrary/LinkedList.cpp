#include "stdafx.h"
#include<iostream>
using namespace std;
struct Node {
	int value;
	Node *next=NULL;
	Node *prev=NULL;
};
Node *head = NULL;
//functions starts here
Node* insert(int v);
Node*queue(Node *n);
Node*stack();
void print();

//functions ends here


int main() {
	head = insert(10);
	head = insert(9);
	head = insert(8);
	head = insert(7);
	head = insert(6);
	head = insert(5);
	head = insert(4);
	head = insert(3);
	head = insert(2);
	head = insert(1);
	print();

	return 0;
}
//inserts at the last
Node* insert(int v) {
	if (head == NULL) {
		Node *x = new Node();
		x->value = v;
		head = x;
		return head;
	}
	else {
		Node *tmp = head;
		Node *tr = new Node();
		tr->value = v;
		while (tmp->next!=NULL) {
			//cout << tmp->value;
			tmp = tmp->next;
		}
		tmp->next = tr;
		return head;
	}
}
Node*queue(Node *h) {
	return nullptr;
}
Node*stack() {
	if (head == NULL) {
		return NULL;
	}
	else {
		Node *x=NULL;
		Node *tmp = head;
		Node*t = tmp->next;
		while (tmp) {
			if (x == NULL) {
				x = tmp;
				x->next = NULL;
				tmp = t->next;
			}
			else {
				Node*t = tmp->next;
				tmp = t->next;
			}
			
		}
	
	}
}
void print() {
	if (head == NULL) {
		cout << "Nothing!";
	}
	else {
		Node *tmp = head;
		while (tmp!=NULL) {
			cout << tmp->value << endl;
			tmp = tmp->next;
		}
	}
}