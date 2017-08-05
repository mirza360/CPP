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
vector<Node*>vct(1777);
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
	//vector<Node*>fr = 
	Freq(fileName, vct);
	/*for (int idx = 0; idx <(int) fr.size(); idx++) {
	hs.push_back(fr[idx]);
	}*/
}
//Function implementation
void Frequency::Freq(string filename, vector<Node*>&vct) {
	//Node *arr[pNum];
	//vector<Node*>vct;
	string line;
	//string word="";
	ifstream myfile;
	myfile.open(filename);
	if (myfile) {
		while (myfile >> line) {
			//cout << line << endl;
			string st = tokenize(line);
			int res = wordToInt(st);
			wCount++;
			//cout << word<<endl;
			//testing starts
			

			//cout << "Key Value: " << res << " ";
			//conversion to number ends
			//--create the word node
			Node *wrd = new Node();
			wrd->key = st;
			wrd->total++;
			//-position side node
			//Node*pos = new Node();
			//pos->pos = wCount;
			if (vct[res] == NULL) {
				vct[res] = new Node();
			}
			//if has table index empty
			if (!vct[res]->begin) {
				//float a = (float)wrd->total / (float)wCount;

				vct[res]->value = res;
				vct[res]->begin = true;
				vct[res]->next = wrd;
				
				//cout << "begin 1" << endl;

			}//if table index already has something
			else {
				//checking for duplicate
				Node *idx = vct[res]->next;
				Node*tmp = vct[res];
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
						tmp = idx;
						idx = idx->next;
					}
				}
				//if no duplicate found
				if (check == false) {
					tmp->next = wrd;
				}

			}

			//testing ends
		}
		//print here

		for (int i = 0; i < pNum; i++) {
			//vct.push_back(arr[i]);
			if (vct[i]) {
				Node* tmp = vct[i]->next;
				while (tmp) {
					float a = (float)(tmp->total) / (float)(wCount);
					tmp->freq = a;
					tmp = tmp->next;
				}
				
			}
		}
		//printVector(vct);
		//print ends
	}
	else {
		cout << "Unable to open";

	}
	//return vct;
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
int Frequency::wordToInt(string st)
{
	int result = 0;
	for (int idx = 0; idx < (int)st.size(); idx++) {
		result = result + (int)st.at(idx);
	}
	result = result % 1777;
	return result;
}
void Frequency::printVector() {
	for (int idx = 0; idx < pNum; idx++) {
		if (vct[idx]) {

			while (vct[idx]->next) {
				cout << vct[idx]->next->key << " - " << vct[idx]->next->freq << endl;
				vct[idx]->next = vct[idx]->next->next;
			}
			//cout << "Hi";
		}

	}
}

void Frequency::CloneVector(vector<Node*> &vx)
{
	for (int i = 0; i < pNum; i++) {
		vx[i] = vct[i];
	}
	
}
