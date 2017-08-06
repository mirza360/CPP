#include "stdafx.h"
#include "Frequency.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cctype>
#include<vector>
#include<cmath>
#include <iomanip>
//Global Variables
const int pNum = 1777;
//functions start here
vector<Node*>makeVector(Frequency obj);
string wordReShape(string st);
int wordToInt(string st);
float wordFrequencyInFile(string word, vector<Node*>file);
void printVector(vector<Node*>vct);
vector<string> combinedList(vector<Node*>f1, vector<Node*>v2);
vector<float> frequencyVector(vector<string> list, vector<Node*>file);
float EuclideanDistance(vector<float> v1, vector<float> v2);
float distance(vector<float> v1, vector<float> v2);
void printList(vector<string>list);
//functions end here
using namespace std;
int main() {
	cout << fixed;
	//File # 1
	Frequency f("file.txt");
	vector<Node*>file1(pNum);
	f.CloneVector(file1);
	printVector(file1);
	cout << "Finding Word Frequency!" << endl;
	cout <<"it - "<< wordFrequencyInFile("it", file1);
	//File # 2
	Frequency f2("file3.txt");
	vector<Node*> file2(pNum);
	f2.CloneVector(file2);
	printVector(file2);
	cout << "Finding Word Frequency!" << endl;
	cout << "it - " << wordFrequencyInFile("it", file2);
	//CombinedList
	vector<string>WordList = combinedList(file1, file2);
	//cout << "Combined List is Here----------" << endl;
	/*for (int id = 0; id < (int)WordList.size(); id++) {
		cout << WordList[id] << endl;
	}*/
	//End of Combined List
	//frequency Vector
	vector<float> v1 = frequencyVector(WordList, file1);
	vector<float> v2 = frequencyVector(WordList, file2);
	/*for (int id = 0; id < (int)v1.size(); id++) {
		cout << v1[id] << endl;
	}*/
	float dist=distance(v1, v2);
	cout << "----------++++++++++++-------------" << endl;
	cout << dist << endl;
	printList(WordList);
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
		//cout<<file[num]->value<<endl;
		Node*idx = file[num]->next;
		//cout<<idx->key<<endl;
		while (idx) {
			//cout << idx->key << endl;
			if (idx->key.compare(wd) == 0) {
				result = idx->freq;
				//cout << idx->freq << endl;
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
	//cout << "I am up here!" << endl;
	for (int idx = 0; idx < pNum; idx++) {
		if (vct[idx]) {
			Node* tmp = vct[idx]->next;
			while (tmp) {
				//cout << "Hello" << endl;
				cout << tmp->key << " - " << tmp->freq << endl;
				tmp = tmp->next;
			}
			//cout << "Hi";
		}

	}
}
vector<string> combinedList(vector<Node*>f1, vector<Node*>f2) {
	vector<string> result;
	for (int idx = 0; idx < pNum; idx++) {
		//if any of the tables have something
		if (f1[idx] || f2[idx]) {
			//taking the first file's data
			if (f1[idx]) {
				Node* tmp = f1[idx]->next;
				while (tmp) {
					result.push_back(tmp->key);
					tmp = tmp->next;
				}
			}//taking file 2 and check for duplicacy
			if (f2[idx]) {
				Node* tmpF2 = f2[idx]->next;
				Node* tmpF1 = f2[idx]->next;
				while (tmpF2) {
					string wd = tmpF2->key;
					bool check = false;
					//Running loop for each of the word 
					//at the file 1's table
					while (tmpF1) {
						if (wd.compare(tmpF1->key)) {
							check = true;
						}
						tmpF1 = tmpF1->next;
					}
					if (check == false) {
						result.push_back(tmpF2->key);
					}
					tmpF2 = tmpF2->next;
				}
			}
		}
	}

	return result;
}
vector<float> frequencyVector(vector<string> list, vector<Node*>file) {
	vector<float>res;
	for (int idx = 0; idx < (int)list.size(); idx++) {
		res.push_back(wordFrequencyInFile(list[idx], file));
	}
	return res;
}
float EuclideanDistance(vector<float> v1, vector<float> v2) {
	float result = 0.0;
	for (int idx = 0; idx < (int)v1.size(); idx++) {
		float tmp = v1[idx] - v2[idx];
		result = result + pow(tmp, 2);
	}
	result = pow(result, .5);
	return result;
}
float distance(vector<float> v1, vector<float> v2) {
	float result = 0.0;
	float tmp = 1 / (float)v1.size();
	result = tmp*EuclideanDistance(v1, v2);
	return result;
}
void printList(vector<string>list) {
	cout << "Printing List of Words: " << endl;
	if ((int)list.size()>0) {
		for (int idx = 0; idx < (int)list.size(); idx++) {
			cout << list[idx] << endl;
		}
	}
}