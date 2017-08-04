#include "stdafx.h"
#include "Frequency.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cctype>
#include<vector>

//global variable area
int sCount = 0;
int wCount = 0;
const int pNum = 1777;//the prime number
Node *arr[1777];
vector<Node*>hs;
//end of global variables
using namespace std;
Frequency::Frequency(string st) {
	FileOpen(st);
}
Frequency::~Frequency() {
	for (int id = 0; id < 1777; id++) {
		if (arr[id]) {
			Node*tmp = arr[id]->next;
			while (tmp) {
				delete(tmp);
				tmp = tmp->next;
			}
			delete(arr[id]);
		}
	}
	
	//delete(arr);
}
void Frequency::FileOpen(string fileName)
{
	
	//cout << "Enter the .txt file name: ";
	//string fileName;
	//cin >> fileName;
	//myfile.open("file.txt");
	vector<Node*>fr=Freq(fileName);
	/*for (int idx = 0; idx <(int) fr.size(); idx++) {
		hs.push_back(fr[idx]);
	}*/
}
//Function implementation
vector<Node*> Frequency::Freq(string filename) {
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
				arr[res]->value = res;
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
				//if no duplicate found
				if (check == false) {
					idx = wrd;
				}

			}

			//testing ends
		}
		//print here
		
		for (int i = 0; i < pNum; i++) {
			vct.push_back(arr[i]);
			if (arr[i]) {
				
				float a = (float)(vct[i]->next->total) / (float)(wCount);
				//printf("%.4f: ", a);
				//a = a * 100000;
				//int dd = (int)a;
				//a = dd / 10000.0;
				//a = floor(a * 10000.0) / 10000.0;
				vct[i]->freq = a;
			}
		}
		printVector(vct);
		//print ends
	}
	else {
		cout << "Unable to open";
		
	}
	return vct;
}
string Frequency::tokenize(string st) {

	//cout << endl << st.size() << endl;
	string word = "";
	//string snt = "";
	//running a loop where each char of st will be assigned to c
	char c;
	for (int idx = 0; idx < (int)st.size(); idx++) {
		c = st.at(idx);
		if (!ispunct(c) && isalpha(c) && !isspace(c)) {
			word += tolower(c);
		}

	}
	//cout << word;
	return word;


}
void Frequency::printVector(vector<Node*>vct) {
	for (int idx = 0; idx < pNum; idx++) {
		if (vct[idx]) {

			while (vct[idx]->next) {
				cout << vct[idx]->next->key << " - " << vct[idx]->freq << endl;
				vct[idx]->next = vct[idx]->next->next;
			}
			//cout << "Hi";
		}

	}
}
Node* getVectorElements(int idx) {
	return arr[idx]->next;
}
