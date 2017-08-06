
#include "stdafx.h"
#include "Frequency.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cctype>
#include<vector>
#include<cmath>
#include <iomanip>
#include <Windows.h>
//Global Variables
const int pNum = 1777;
//functions start here
void FileDriver(vector<string> fileList, vector<Frequency>&fileObject);
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
vector < vector<float>> createMatrix(vector<vector<Node*>>fileHash);
void printMatrix(vector < vector<float>>mat);
//functions end here
using namespace std;
int main(int argc, char *argv[]) {
	//cout << fixed;
	cout << "Processing your files!" << endl;
	//vector<string>fileList(argc);
	/*
	**********************************************************
	File preparation starts here
	-----------------------------
	*/

	vector<Frequency>fileObject;
	vector<vector<Node*>>fileHash;
	for (int idx = 1; idx < argc; idx++) {
		string fileName=argv[idx];
		cout << fileName << endl;
		Sleep(1000);
		Frequency f(fileName);
		fileObject.push_back(f);
		vector<Node*>fileH(pNum);
		f.CloneVector(fileH);
		fileHash.push_back(fileH);
		printVector(fileHash[idx-1]);
		Sleep(1000);
	}

	//Vector to store objects
	//vector<Frequency>fileObject;
	//FileDriver(fileList, fileObject);
	//operations for each file
	// ((int)fileObject.size());
	/*for (int idx = 0; idx < (int)fileObject.size(); idx++) {
		vector<Node*>fileH(pNum);
		fileObject[idx].CloneVector(fileH);
		//fileHash[idx] = fileH;
		fileHash.push_back(fileH);
		printVector(fileHash[idx]);
	}*/

	/*
	-----------------------------
	fileObject beholds the objects only
	fileHash beholds the hash table for the respective object
	info stored according to vector index
	-----------------------------
	File Preparation ends here
	**********************************************************
	*/
	//Code Starts here
	//printVector(fileHash[0]);
	//cout << "Select File Number: ";
	//int fileNum;
	//cin >> fileNum;
	//fileNum = fileNum - 1;//for vector fileHash purpose
	//vector<Node*>targetFile = fileHash[fileNum];

	while (true)
	{
		cout << "\nPlease Select which task you want to complete or enter 7 to exit!";
		int task = 0;
		cin >> task;
		if (task>0 && task<7)
		{
			switch (task) {
			case 1: {
				cout << "Beginning Task 1\n ";
				cout << "Enter Word: ";
				string wdx;
				cin >> wdx;
				wdx = wordReShape(wdx);
				cout << "Enter File Number: ";
				int fileNum;
				cin >> fileNum;
				fileNum = fileNum - 1;//for vector fileHash purpose
				vector<Node*>targetFile = fileHash[fileNum];
				cout << "Word Frequency in File # " << (fileNum + 1)<<" - "<< wordFrequencyInFile(wdx, targetFile);
				cout << endl;
			}break;
			case 2: {
				cout << "Beginning Task 2\n ";
				cout << "First File Number:";
				int fileNum1=0;
				cin >> fileNum1;
				fileNum1 = fileNum1 - 1;//for vector fileHash purpose
				vector<Node*>targetFile1 = fileHash[fileNum1];
				cout << "Enter Second File Number: ";
				int fileNum2 = 0;
				cin >> fileNum2;
				fileNum2 = fileNum2 - 1;//for vector fileHash purpose
				vector<Node*>targetFile2 = fileHash[fileNum2];
				cout << "Generating Combined List"<<endl;
				vector<string>FSList=combinedList(targetFile1, targetFile2);
				cout << "If you want to print the list enter 1" << endl;
				int op = 0;
				cin >> op;
				if (op == 1) {
					printList(FSList);
				}
				cout << endl;

			}break;
			case 3: {
				cout << "Beginning Task 3\n ";
				cout << "First File Number:";
				int fileNum1 = 0;
				cin >> fileNum1;
				fileNum1 = fileNum1 - 1;//for vector fileHash purpose
				vector<Node*>targetFile1 = fileHash[fileNum1];
				cout << "Enter Second File Number: ";
				int fileNum2 = 0;
				cin >> fileNum2;
				fileNum2 = fileNum2 - 1;//for vector fileHash purpose
				vector<Node*>targetFile2 = fileHash[fileNum2];
				cout << "Generating Combined List" << endl;
				vector<string>FSList = combinedList(targetFile1, targetFile2);
				cout << "Insert File Number to evaluate frequency vector: ";
				int fileNum3 = 0;
				cin >> fileNum3;
				fileNum3 = fileNum3 - 1;//for vector fileHash purpose
				vector<float> v1=frequencyVector(FSList, fileHash[fileNum3]);
				int op = 0;
				cout << endl << "To Print input 1";
				cin >> op;
				if (op == 1) {
					for (int idx = 0; idx <(int) v1.size(); idx++) {
						cout << v1[idx] << "  ";
					}
				}
				cout << endl;
			}break;
			case 4: {
				cout << "Beginning Task 3\n ";
				cout << "First File Number:";
				int fileNum1 = 0;
				cin >> fileNum1;
				fileNum1 = fileNum1 - 1;//for vector fileHash purpose
				vector<Node*>targetFile1 = fileHash[fileNum1];
				cout << "Enter Second File Number: ";
				int fileNum2 = 0;
				cin >> fileNum2;
				fileNum2 = fileNum2 - 1;//for vector fileHash purpose
				vector<Node*>targetFile2 = fileHash[fileNum2];
				cout << "Generating Combined List" << endl;
				vector<string>FSList = combinedList(targetFile1, targetFile2);
				cout << "Insert first File Number to evaluate frequency vector: ";
				int fileNum3 = 0;
				cin >> fileNum3;
				fileNum3 = fileNum3 - 1;//for vector fileHash purpose
				vector<float> v1 = frequencyVector(FSList, fileHash[fileNum3]);
				//second file
				cout << "Insert Second File Number to evaluate frequency vector: ";
				int fileNum4 = 0;
				cin >> fileNum4;
				fileNum4 = fileNum4 - 1;//for vector fileHash purpose
				vector<float> v2 = frequencyVector(FSList, fileHash[fileNum4]);
				cout << endl << "Distance between the two files:" << distance(v1, v2);
				cout << endl;
			}break;
			case 5: {
				cout << "Creating the Matrix: " << endl;
				vector < vector<float>>mat=createMatrix(fileHash);
				cout << "If you want to print the Whole Matrix enter 1" << endl;
				int op = 0;
				cin >> op;
				if (op == 1) {
					printMatrix(mat);
				}
				cout << endl;
			}break;
			default: {
			}break;
			}
		}
		else {
			break;
		}
		
	}

	//printVector(targetFile);
	//Code Ends here
/*	
	//File # 1
	Frequency f("a.txt");
	vector<Node*>file1(pNum);
	f.CloneVector(file1);
	f.~Frequency();
	printVector(file1);
	Sleep(1000);
	cout << "Finding Word Frequency!" << endl;
	cout <<"it - "<< wordFrequencyInFile("it", file1);
	//File # 2
	Frequency f2("b.txt");
	vector<Node*> file2(pNum);
	f2.CloneVector(file2);
	f2.~Frequency();
	printVector(file2);
	Sleep(1000);
	cout << "Finding Word Frequency!" << endl;
	cout << "it - " << wordFrequencyInFile("it", file2);
*/	
	//CombinedList
	//vector<string>WordList = combinedList(file1, file2);
	//cout << "Combined List is Here----------" << endl;
	/*for (int id = 0; id < (int)WordList.size(); id++) {
		cout << WordList[id] << endl;
	}*/
	//End of Combined List
	//frequency Vector
	/*
	vector<float> v1 = frequencyVector(WordList, file1);
	vector<float> v2 = frequencyVector(WordList, file2);
	*/
	/*float dist=distance(v1, v2);
	cout << "----------++++++++++++-------------" << endl;
	cout << dist << endl;
	printList(WordList);

	*/
	return 0;
}
void FileDriver(vector<string> fileList, vector<Frequency>&fileObject) {
	for (int idx = 0; idx < (int)fileList.size(); idx++) {
		string fileName = fileList[idx];
		Frequency f(fileName);
		fileObject.push_back(f);
	}
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
			int vctIdx = (int)result.size();
			//add all element of file 1 hash
			if (f1[idx]) {
				Node* tmp = f1[idx]->next;
				while (tmp) {
					result.push_back(tmp->key);
					tmp = tmp->next;
				}
			}
			//add all elements of file 2 if f1's hash was empty
			if (f2[idx] && vctIdx== (int)result.size()) {
				Node* tmp = f2[idx]->next;
				while (tmp) {
					result.push_back(tmp->key);
					tmp = tmp->next;
				}
			}
			//if both files hash exists
			//we check for duplicacy in f2's hash
			//provided that f1's hash will be appended
			//at the very beginning
			if (f1[idx] && f2[idx]) {
				Node* tmp = f2[idx]->next;
				while (tmp) {
					string FST = tmp->key;
					bool check = false;
					for (int idx = vctIdx; idx < (int)result.size(); idx++) {
						if (FST.compare(result[idx])==0) {
							check = true;
							break;
						}
					}
					if (check == false) {
						result.push_back(tmp->key);
					}
					tmp = tmp->next;
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
vector < vector<float>> createMatrix(vector<vector<Node*>>fileHash) {
	int x = (int)fileHash.size();
	vector < vector<float>>col;
	int height = x;
	for (int r = 0; r<height; r++)
	{
		vector<float> row;
		for (int c = 0; c < height; c++) {
			if (c == r) {
				row.push_back(0.0);
				cout << 0.0;
			}
			else if(c<r){
				//taking advantage of symmetricity
				row.push_back(col[c][r]);
				cout << col[c][r];
			}
			else if(c>r){
				//do the distance operations
				//combine List
				vector<string>CombList = combinedList(fileHash[c], fileHash[r]);
				//Frequency Vector for each of the pair
				vector<float> v1 = frequencyVector(CombList, fileHash[c]);
				vector<float> v2 = frequencyVector(CombList, fileHash[r]);
				//finding distance
				float dist = distance(v1, v2);
				cout << dist;
				row.push_back(dist);
			}
		}
		cout << endl;
		col.push_back(row);
	}

	return col;
}
void printMatrix(vector < vector<float>>mat) {
	int size = (int)mat.size();
	cout << "----------------------------";
	cout << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j == 0) {
				cout << "|";
			}
			cout<<mat[i][j]<<" | ";
		}
		cout << endl;
		cout << "----------------------------";
		cout << endl;
	}
}