// list.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
//#include"Node.h"
#include "Node.cpp"
#include<iostream>

using namespace std;


int main()
{
	Node*head = NULL;
	Node*n = new Node();
	head = n;
	cout << "Let's Create the first link!"<<endl<<"Please Enter the value: ";
	int v;
	cin >> v;
	n->value = v;
	
	//cout << n->value << endl;
	int idx = 0;
	cout << "We'll be adding values to the end" << endl;
	while (idx!=5) {
		cout << "To continue adding press 1, to print press 2 and to terminate press 5" << endl;
		cin >> idx;
		switch (idx) {
		case 1: {
			cout << "Enter Your Value: ";
			int val;
			cin >> val;
			n->addNodeToEnd(head, val);
		}break;
		case 2: {
			cout << "Printing The Values!" << endl;
			n->printNode(head);
		}break;
		case 5: {
			cout << "Terminating!" << endl;
		}break;
		}
	}
	
    return 0;
}

