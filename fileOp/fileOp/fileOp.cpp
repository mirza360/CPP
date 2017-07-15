// fileOp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cctype>

using namespace std;
//global variable area
int sCount = 0;
int wCount = 0;
const int pNum = 1777;//the prime number

//constructor Areas
//array indexing

struct Node {
	//common op
	string key;
	int val;
	Node *next = NULL;
	Node *Lst = NULL;
	//special for the first one
	int total = 0;
	bool begin = false;
	Node *last = NULL;
	//for the key occurence
	int occ = 0;
	bool recur = true;
	Node *side = NULL;
	int pos = -1;
	//for active list
	Node *actN = NULL;
};
//Structure related global variables
Node *activeList = new Node();
Node*actHead = activeList;
Node *arr[pNum];

//Functions area
void tokenize(string st);
void insert(string st);
void print();
//void brunching(Node *br, Node *n);

//Main function
int main(/*char *argv[]*/)
{
	string line;
	ifstream myfile;
	myfile.open("file.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//cout << line<<endl;
			tokenize(line);
		}
		print();
		myfile.close();
		
	}
	else {
		cout << "Unable to open";
	}
	return 0;
}
//Function implementation
void tokenize(string st) {

	cout << endl << st.size() << endl;
	string word = "";
	string snt = "";
	//running a loop where each char of st will be assigned to c
	for (int idx = 0; idx < (int)st.size(); idx++) {
		if ((int)st.at(idx) >=0 && (int)st.at(idx) <= 255) {
			

			char c = st.at(idx);
			c = tolower(c);
			//dot operation
			if (c != '.' && !isspace(c)  && !ispunct(c) && c!='\n') {
				
				word += c;
			}
			else if (c == '.' || c == ' ' || c == '\n') {

				//got our word ready!

				
				if (!word.empty()) {
					wCount++;
					
					cout << "Word # " << wCount << " : ";
					//cout << word << endl;
					insert(word);
					word.erase();
				}

			}

			//word = "";

			//}/


		}
		
	}

	//cout << snt;

}
//insert operation
void insert(string st) {
	//converting into number
	int res = 0;
	for (int idx = 0; idx < (int)st.size(); idx++) {
		res += (int)st.at(idx);
	}
	cout << res;
	//conversion to number ends
	//Creating the node
	Node *n = new Node();
	n->key = st;
	n->val = res;
	n->pos = wCount;
	n->next = NULL;
	//insert
	int arrPos = res%pNum;
	if (arr[arrPos] == NULL) {
		Node*act = new Node();
		act->val = arrPos;
		activeList = act;
		activeList = activeList->actN;
		arr[arrPos] = new Node();
		arr[arrPos]->begin = true;
	}
	if (arr[arrPos]->begin = true) {
		Node *x = arr[arrPos]->next;//as we will be using the arr[arrPos] as head

		if (x == NULL) {
			x = n;
			cout << x->key<<endl;
		}
		else {
			while (x != NULL) {
				//comparing if exists
				if (x->key == n->key) {
					x->total++;
					x->recur = true;
					x->side = new Node();
					//checking for recurrence
					if (x->side->begin == false) {
						x->side->begin = true;
						x->side->pos = n->pos;
					}
					else {
						while (x->side->begin != false) {
							cout << x->side->pos;
							x->side = x->side->next;
						}
						x->side->begin = true;
						x->side->pos = n->pos;
						cout << x->side->pos;
					}
					break;
				}
				else {
					x = x->next;
				}
				
				cout << x->key << endl;
			}
			x = n;
			cout << x->key << endl;
		}
		
	}
	
}//insert ends here
//brunch insert starts here
/*
void brunching(Node *br, Node *n) {
	if (br == NULL) {
		br = new Node();
		br->begin = true;
	}
	int x = n->key.at(0);
	if (br->brIdx[x]->begin == false) {
		br->brIdx[x] = new Node();
		br->brIdx[x]->begin = true;
	}
	Node *bx = br->brIdx[x]->next;
	if (bx == NULL) {
		bx = n;
		bx->begin = true;
		bx->total++;
		
	}
	else {
		while (bx != NULL) {
			if (bx->key == n->key) {

			}
		}
	}
	
}//brunching ends here

*/
void print() {
	Node *tmp = actHead;
	/*if (actHead != NULL) {
		while (tmp != NULL) {
			int tVal = tmp->val;
			//Now traverse throught the arr[tVal]
			Node*x = arr[tVal]->next;
			while (x != NULL) {
				cout << "Word: " << x->key << " :";
				if (x->total > 0) {
					Node *y = x->side->next;
					while (y != NULL) {
						cout << y->val<<" ,";
						y = y->next;
					}
				}
			}
			tmp = tmp->next;
		}
	}*/
	for (int idx = 0; idx < pNum; idx++) {
		if (arr[idx]->begin==true) {
			tmp = arr[idx]->next;
			cout << tmp->key;
		}
	}
}