// fileOp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cctype>

using namespace std;
//constructor Areas

struct Node {
	//common op
	string key="";
	
};
//For the linked list of words
struct Link {
	string wrd = "";
	Link * next = NULL;
	Occ * side = NULL;
	int total = 0;
	Occ* last = NULL;
};
Link *head = NULL;
//Structure related global variables
//for the occurence linked lis
struct Occ {
	Occ*next = NULL;
	int pos = 0;
};

//Functions area
string tokenize(string st);
//void insert(string st);
//void print();
//void brunching(Node *br, Node *n);

//Main function
int main()
{
	int sCount = 0;
	int wCount = 0;
	const int pNum = 1777;//the prime number
	Node *arr[pNum];
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

			
			//testing ends
		}		//print ends
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

