#include "stdafx.h"
#include "Frequency.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cctype>
#include<vector>
//Global Variables
const int pNum = 1777;
//functions start here
vector<Node*>makeVector(Frequency obj);
string wordReShape(string st);
int wordToInt(string st);
float wordFrequencyInFile(string word, vector<Node*>file);
//void printVector(vector<Node*>vct);
//functions end here
using namespace std;
int main() {
	Frequency f("file.txt");
	//f.FileOpen("file.txt");
	//vector<Node*>fl =
	//cout << fl.size();
	//printVector(fl);
	//cout << wordFrequencyInFile("it", fl);
	//f.~Frequency();
	//Frequency f2;
	//f2.FileOpen("file3.txt");
	//f2.~Frequency();


	return 0;
}
float wordFrequencyInFile(string word, vector<Node*>file) {
	string wd = wordReShape(word);
	int num = wordToInt(wd);
	//cout << file[221]->next->key << endl;
	//cout << wd << endl;
	//cout << num << endl;
	float result = 0.0;
	if (file[num]) {
		Node*idx = file[num]->next;
		while (idx) {
			cout << idx->key << endl;
			if (idx->key.compare(wd) == 0) {
				result = idx->freq;
				cout << idx->freq << endl;
				break;
			}
			else {
				idx = idx->next;
			}
		}

	}
	return result;
}
string wordReShape(string st) {

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
int wordToInt(string st) {
	int result = 0;
	for (int idx = 0; idx < (int)st.size(); idx++) {
		result = result + (int)st.at(idx);
	}
	result = result % 1777;
	return result;
}
void printVector(vector<Node*>vct) {
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
//vector<Node*>makeVector(Frequency obj) {
//	vector<Node*>vct;
//	/*for (int idx = 0; idx < pNum; idx++) {
//	vct.push_back(obj.getVectorElements(idx));
//	}*/
//	return vct;
//}