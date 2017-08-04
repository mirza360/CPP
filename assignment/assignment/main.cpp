#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cctype>
#include<vector>

using namespace std;
//global variable area
int sCount = 0;
int wCount = 0;
const int pNum = 1777;//the prime number

//constructor Areas
//array indexing

struct Node {
	//common op
	string key = "";
	Node *next = NULL;
	//special for the first one
	int total = 0;
	bool begin = false;
};
//Structure related global variables


//Functions area
string tokenize(string st);
vector<Node*> Freq(string fileName);
//void insert(string st);
void printVector(vector<Node*>vct);
//void brunching(Node *br, Node *n);
Node *arr[pNum];
//Main function
int main()
{
	
	//cout << "Enter the .txt file name: ";
	//string fileName;
	//cin >> fileName;
	//myfile.open("file.txt");
	vector<Node*>fr=Freq("file.txt");
	return 0;
}
//Function implementation
vector<Node*> Freq(string filename) {
	//Node *arr[pNum];
	vector<Node*>vct;
	string line;
	//string word="";
	ifstream myfile;
	myfile.open(filename);
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
			//Node*pos = new Node();
			//pos->pos = wCount;
			if (arr[res] == NULL) {
				arr[res] = new Node();
			}
			//if has table index empty
			if (!arr[res]->begin) {
				arr[res]->begin = true;
				arr[res]->next = wrd;
				//cout << "begin 1" << endl;

			}//if table index already has something
			else {
				//checking for duplicate
				Node *idx = arr[res]->next;
				bool check = false;//if duplicate found, it will be true
				while (idx != NULL) {
					//matching the key
					if (idx->key.compare(st) == 0) {
						idx->total++;
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
				}

			}

			//testing ends
		}
		//print here
		
		for (int i = 0; i < pNum; i++) {
			vct.push_back(arr[i]);
		}
		printVector(vct);
		//print ends
	}
	else {
		cout << "Unable to open";
		
	}
	return vct;
}
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
void printVector(vector<Node*>vct) {
	for (int idx = 0; idx < pNum; idx++) {
		if (vct[idx]) {

			while (vct[idx]->next) {
				//cout << arr[idx]->next->total;
				float a = (float)(vct[idx]->next->total) / (float)(wCount);

				cout << vct[idx]->next->key << " - ";
				printf("%.4f: ", a);
				//cout << "";
				cout << endl;
				vct[idx]->next = vct[idx]->next->next;
			}
			//cout << "Hi";
		}

	}
}