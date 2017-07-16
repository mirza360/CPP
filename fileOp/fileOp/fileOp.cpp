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
	string key="";
	int val=-1;
	Node *next = NULL;
	//special for the first one
	int total = 0;
	bool begin = false;
	Node *last = NULL;
	//for the key occurence

	Node *side = NULL;
	int pos = -1;
	//for active list
};
//Structure related global variables
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
		//print();
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
					cout << word << endl;
					insert(word);
					word.erase();
				}

			}

	

		}
		
	}

	
}
//insert operation
void insert(string st) {
	//converting into number
	int res = 0;
	for (int idx = 0; idx < (int)st.size(); idx++) {
		res += (int)st.at(idx);
	}
	res = res%pNum;
	cout << res<<endl;
	//conversion to number ends
	//--create the word node
	Node *wrd = new Node();
	wrd->key = st;
	wrd->total++;
	//-position side node
	Node*pos = new Node();
	pos->pos = wCount;
	cout << pos->pos<<endl;
	/*
	wrd->side = pos;
	wrd->last = pos;*/
	//-end of position side node
	//--end of word node
	if (arr[res] == NULL) {
		arr[res] = new Node();
	}
	//if has table index empty
	if(!arr[res]->begin){
		arr[res]->begin = true;
		arr[res]->next = wrd;
		wrd->side = pos;
		wrd->last = pos;
		cout << "begin 1" << endl;
		
	}//if table index already has something
	else {
		//checking for duplicate
		Node *idx = arr[res]->next;
		bool check = false;//if duplicate found, it will be true
		while (idx != NULL) {
			//matching the key
			if (idx->key.compare(st)==0) {
				//cout << idx->key;
				cout << "begin 2" << endl;
				idx->last->side = pos;
				idx->total++;
				idx->last = pos;
				//delete (wrd);
				check = true;
				break;
			}//if not matched
			else {
				idx = idx->next;
			}
		}
		if (check == false) {
			idx = wrd;
			wrd->side = pos;
			wrd->last = pos;
		}
		//debugging
		Node *dx = arr[res]->next->side;
		cout << arr[res]->next->total << endl;
		while (dx != NULL) {
			cout << dx->pos << ", ";
			dx = dx->side;
		}
		//end of debugging
	}
		
}
void print() {
	
}