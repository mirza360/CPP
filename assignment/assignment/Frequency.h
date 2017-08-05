#pragma once
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cctype>
#include<vector>

using namespace std;
struct Node {
	//common op
	int value = 0;
	string key = "";
	Node *next = NULL;
	//special for the first one
	int total = 0;
	float freq = 0.0;
	bool begin = false;
};

class Frequency {
public:


	//Functions
	Frequency(string s);
	~Frequency();
	void FileOpen(string filename);
	string tokenize(string st);
	vector<Node*> Freq(string fileName);
	void printVector(vector<Node*>vct);
	Node* getVectorElements(int idx);




};