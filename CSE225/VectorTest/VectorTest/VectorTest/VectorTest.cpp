//============================================================================
// Name        : test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include"stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cctype>
#include<vector>
using namespace std;


int main(int argc, char *argv[]) {
	string line;
	//string word="";
	ifstream myfile;
	string st = argv[0];
	myfile.open(st);
	if (myfile) {
		while (myfile >> line) {
			//cout << line << endl;
			cout << line << endl;
		}
	}
	else {
		cout << "Couldn't open the file!" << endl;
	}

	return 0;
}
