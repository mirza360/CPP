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


//Functions area
string tokenize(string st);
//void insert(string st);
//void print();
//void brunching(Node *br, Node *n);
Node *arr[pNum];
//Main function
int main()
{
	string line;
	//string word="";
	ifstream myfile;
	cout << "Enter the .txt file name: ";
	string fileName;
	cin >> fileName;
	myfile.open(fileName);
	if (myfile) {
		while (myfile >> line) {
			//cout << line << endl;
			string st = tokenize(line);
			wCount++;
			//cout << word<<endl;
			//testing starts

			int res = 0;
			for (int idx = 0; idx < (int)st.size(); idx++) {
				res += (int)st.at(idx);
			}
			res = res%pNum;
			//cout << "Key Value: " << res << " ";
			//conversion to number ends
			//--create the word node
			Node *wrd = new Node();
			wrd->key = st;
			wrd->total++;
			//-position side node
			Node*pos = new Node();
			pos->pos = wCount;
			//cout << "Current Position" << pos->pos << endl;
			/*
			wrd->side = pos;
			wrd->last = pos;*/
			//-end of position side node
			//--end of word node
			if (arr[res] == NULL) {
				arr[res] = new Node();
			}
			//if has table index empty
			if (!arr[res]->begin) {
				arr[res]->begin = true;
				arr[res]->next = wrd;
				wrd->side = pos;
				wrd->last = pos;
				//cout << "begin 1" << endl;

			}//if table index already has something
			else {
				//checking for duplicate
				Node *idx = arr[res]->next;
				bool check = false;//if duplicate found, it will be true
				while (idx != NULL) {
					//matching the key
					if (idx->key.compare(st) == 0) {
						//cout << idx->key;
						//cout << "begin 2" << endl;
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
				/*
				Node *dx = arr[res]->next->side;
				cout << arr[res]->next->total << endl;
				while (dx != NULL) {
				cout << dx->pos << ", ";
				dx = dx->side;
				}*/
				//end of debugging
			}

			//testing ends
		}
		//print here
		//cout << "Hello";
		for (int idx = 0; idx < pNum; idx++) {
			if (arr[idx]) {
				
				while (arr[idx]->next) {
					//cout << arr[idx]->next->total;
					float a = (float)(arr[idx]->next->total) / (float)(wCount);
					
					cout << arr[idx]->next->key << " - ";
					printf("%.4f: ", a);
					//cout << "";
					while (arr[idx]->next->side) {
						if (arr[idx]->next->side->side == NULL) {
							cout << arr[idx]->next->side->pos << " ";
						}
						else {
							cout << arr[idx]->next->side->pos << ",";
						}
						arr[idx]->next->side = arr[idx]->next->side->side;
					}
					cout << endl;

					arr[idx]->next = arr[idx]->next->next;
				}
				//cout << "Hi";
			}

		}
		//print ends
	}
	else {
		cout << "Unable to open";
	}
	return 0;
}
//Function implementation
string tokenize(string st) {

	//cout << endl << st.size() << endl;
	string word = "";
	//string snt = "";
	//running a loop where each char of st will be assigned to c
	char c;
	for (int idx = 0; idx < (int)st.size(); idx++) {
		c = st.at(idx);
		if (!ispunct(c) && isalpha(c)) {
			word += tolower(c);
		}
		
	}
	//cout << word;
	return word;

	
}
//insert operation

