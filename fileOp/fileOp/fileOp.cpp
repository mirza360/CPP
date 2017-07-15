// fileOp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <cctype>
using namespace std;
int sCount = 0;
int wCount = 0;
void tokenize(string st);
int main(/*char *argv[]*/)
{
	string line;
	ifstream myfile;
	myfile.open("file.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//cout << line<<endl;
			tokenize(line);
		}
		myfile.close();
	}
	else {
		cout << "Unable to open";
	}
	return 0;
}

void tokenize(string st) {

	cout << endl << st.size() << endl;
	string word = "";
	string snt = "";
	//running a loop where each char of st will be assigned to c
	for (int idx = 0; idx < (int)st.size(); idx++) {
		if ((int)st.at(idx) >=0 && (int)st.at(idx) <= 255) {
			

			char c = st.at(idx);
			c = tolower(c);
			//dot operation
			if (c != '.' && c != ' '  && !ispunct(c)) {

				word += c;
			}
			else if (c == '.' || c == ' ' || c == '\n') {

				//got our word ready!

				wCount++;

				cout << "Word # " << wCount << " : ";
				cout << word << " size: " << sizeof(word) << endl;
				word.erase();

			}

			//word = "";

			//}/


		}
		
	}

	//cout << snt;

}