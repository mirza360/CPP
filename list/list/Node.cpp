#include "stdafx.h"
//#include "Node.h"
#include<iostream>

using namespace std;
struct Node
{
	int value;
	
	Node *next=NULL;

	void printNode(Node *head) {
		Node*idx=head;
		while (idx != NULL) {
			cout << idx->value << " ";
			idx = idx->next;
		}
		cout << endl;
	}
	void addNodeToEnd(Node* head, int v) {
		Node *n = new Node();
		n->value = v;
		n->next = NULL;
		if (head->next == NULL) {
			head->next = n;
		}
		else {
			Node *idx = head;
			while (idx->next != NULL) {
				idx = idx->next;
			}
			idx->next = n;
		}
	}
	//Add to the beginning
	void addNodeToFront(Node* head, int v) {
		Node *n = new Node();
		n->value = v;
		n->next = NULL;
		if (head == NULL) {
			head = n;
		}
		else {
			Node *tmp = head;
			head = n;
			n->next = tmp;
			tmp = NULL;
		}
	}
};
//Node*head = NULL;